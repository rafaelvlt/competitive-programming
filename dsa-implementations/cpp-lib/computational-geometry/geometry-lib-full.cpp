/**
 * ============================================================================
 * COMPENDIUM DE GEOMETRIA COMPUTACIONAL (CP3 CAPÍTULO 7)
 * ============================================================================
 * * ÍNDICE DE BUSCA RÁPIDA (Ctrl+F):
 * * [CONST]   Constantes e Utilitários (PI, EPS, radianos)
 * [7.2.1]   Pontos (Definição, Distância, Rotação)
 * [7.2.2]   Linhas e Vetores (Eq. Reta, Paralelismo, Interseção, Vetores)
 * [7.2.3]   Círculos (Dentro/Fora, Área, Setor, Acorde, Centro por 2 pontos)
 * [7.2.4]   Triângulos (Áreas, Heron, InCircle, CircumCircle, Lei Cossenos)
 * [7.2.5]   Quadriláteros (Retângulo, Quadrado, Trapézio, Paralelogramo, Pipa, Losango)
 * [7.3.1]   Polígonos - Representação
 * [7.3.2]   Polígonos - Perímetro
 * [7.3.3]   Polígonos - Área (Shoelace)
 * [7.3.4]   Polígonos - Convexidade
 * [7.3.5]   Polígonos - Ponto Interno (Winding Number)
 * [7.3.6]   Polígonos - Corte (Sutherland-Hodgman)
 * [7.3.7]   Polígonos - Convex Hull (Graham Scan)
 * * ============================================================================
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

// =========================================================
// [CONST] CONSTANTES E UTILITÁRIOS
// =========================================================

const double INF = 1e9;
// EPS: Tolerância para comparações de ponto flutuante (Evita erros de precisão)
const double EPS = 1e-9;
// PI: Valor preciso de PI
const double PI = acos(-1.0);

// Converte Graus para Radianos (Funções trigonométricas do C++ usam rad)
double DEG_to_RAD(double theta) { return theta * PI / 180.0; }

// =========================================================
// [7.2.1] 0D OBJECTS: POINTS (PONTOS)
// Definição: Um local no espaço definido por coordenadas (x, y).
// =========================================================

struct point {
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}

    // Ordenação (necessária para algoritmos de varredura e sets)
    // Prioridade: Menor X, depois Menor Y.
    bool operator < (point other) const {
        if (fabs(x - other.x) > EPS) return x < other.x;
        return y < other.y;
    }

    // Igualdade (com tolerância EPS)
    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }
};

// Distância Euclidiana: d = sqrt((x1-x2)^2 + (y1-y2)^2)
double dist(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

// Rotação: Gira o ponto 'p' por 'theta' graus no sentido anti-horário em torno da origem (0,0).
point rotate(point p, double theta) {
    double rad = DEG_to_RAD(theta);
    return point(p.x * cos(rad) - p.y * sin(rad),
                 p.x * sin(rad) + p.y * cos(rad));
}

// =========================================================
// [7.2.2] 1D OBJECTS: LINES & VECTORS (LINHAS)
// Definições de retas infinitas, segmentos e operações vetoriais.
// =========================================================

// Estrutura de Linha: ax + by + c = 0
struct line { double a, b, c; };

// Converte 2 pontos em uma Linha (ax + by + c = 0)
void pointsToLine(point p1, point p2, line &l) {
    if (fabs(p1.x - p2.x) < EPS) { // Linha Vertical
        l.a = 1.0; l.b = 0.0; l.c = -p1.x;
    } else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
}

// Verifica se linhas são paralelas (coeficientes a e b proporcionais)
bool areParallel(line l1, line l2) {
    return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}

// Verifica se linhas são a mesma (coincidentes)
bool areSame(line l1, line l2) {
    return areParallel(l1, l2) && (fabs(l1.c - l2.c) < EPS);
}

// Interseção de duas retas
bool areIntersect(line l1, line l2, point &p) {
    if (areParallel(l1, l2)) return false;
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else                  p.y = -(l2.a * p.x + l2.c);
    return true;
}

// --- VETORES E OPERAÇÕES ---

struct vec { double x, y; vec(double _x, double _y) : x(_x), y(_y) {} };

// Ponto A para Ponto B
vec toVec(point a, point b) { return vec(b.x - a.x, b.y - a.y); }
// Escalar vetor
vec scale(vec v, double s) { return vec(v.x * s, v.y * s); }
// Transladar ponto por vetor
point translate(point p, vec v) { return point(p.x + v.x, p.y + v.y); }
// Produto Escalar (Dot Product): a.b = |a||b|cos(ang)
double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }
// Norma ao quadrado (|v|^2)
double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }
// Produto Vetorial (Cross Product): a x b = |a||b|sin(ang) -> Área / Orientação
double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

// Distância Ponto a Reta (Infinita)
double distToLine(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));
    return dist(p, c);
}

// Distância Ponto a Segmento (Finita)
double distToLineSegment(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0) { c = point(a.x, a.y); return dist(p, a); }
    if (u > 1.0) { c = point(b.x, b.y); return dist(p, b); }
    return distToLine(p, a, b, c);
}

// Ângulo AOB (em radianos) usando Dot Product
double angle(point a, point o, point b) {
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

// Teste CCW (Counter Clockwise): Ponto r à esquerda de pq?
bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0;
}

// =========================================================
// [7.2.3] 2D OBJECTS: CIRCLES (CÍRCULOS)
// =========================================================

// Ponto dentro do Círculo? 0=Dentro, 1=Borda, 2=Fora
int insideCircle(point p, point c, double r) {
    double dx = p.x - c.x, dy = p.y - c.y;
    double Euc = dx * dx + dy * dy, rSq = r * r;
    return Euc < rSq - EPS ? 0 : Euc > rSq + EPS ? 2 : 1;
}

// Área do círculo: PI * r^2
double circleArea(double r) { return PI * r * r; }
// Perímetro (Circunferência): 2 * PI * r
double circlePerimeter(double r) { return 2 * PI * r; }
// Área do Setor Circular (fatia de pizza) dado ângulo em graus
double circularSectorArea(double r, double thetaDeg) { return (thetaDeg/360.0) * circleArea(r); }

// Encontrar centro dados 2 pontos na borda e o raio
bool circle2PtsRad(point p1, point p2, double r, point &c) {
    double d2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
    double det = r * r / d2 - 0.25;
    if (det < 0.0) return false;
    double h = sqrt(det);
    c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    return true;
}

// =========================================================
// [7.2.4] 2D OBJECTS: TRIANGLES (TRIÂNGULOS)
// =========================================================

// Área (Heron): s = semi-perimetro
double areaHeron(double a, double b, double c) {
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
// Área padrão (base * altura / 2)
double areaTri(double b, double h) { return 0.5 * b * h; }

// Raio do InCircle (Inscrito): r = Area / s
double rInCircle(double ab, double bc, double ca) {
    return areaHeron(ab, bc, ca) / (0.5 * (ab + bc + ca));
}

// Raio do CircumCircle (Circunscrito): R = abc / 4*Area
double rCircumCircle(double ab, double bc, double ca) {
    return ab * bc * ca / (4.0 * areaHeron(ab, bc, ca));
}

// Lei dos Cossenos: c^2 = a^2 + b^2 - 2ab cos(gamma)
// Útil para achar o terceiro lado ou um ângulo.
double cosineRule(double a, double b, double gammaDeg) {
    return sqrt(a*a + b*b - 2*a*b*cos(DEG_to_RAD(gammaDeg)));
}

// =========================================================
// [7.2.5] 2D OBJECTS: QUADRILATERALS (QUADRILÁTEROS)
// Definições e Fórmulas conforme Seção 7.2.5
// =========================================================

// 1. QUADRILÁTERO GERAL
// Definição: Polígono com 4 arestas e 4 vértices.
// A área de um quadrilátero geral (convexo) pode ser calculada dividindo em 2 triângulos
// ou usando a fórmula Shoelace (vide Seção 7.3).

// 2. RETÂNGULO (RECTANGLE)
// Definição: Polígono com 4 arestas, 4 vértices e 4 ângulos retos (90 graus).
double areaRectangle(double width, double height) { return width * height; }
double perimeterRectangle(double width, double height) { return 2.0 * (width + height); }

// Verifica se 4 pontos formam um retângulo (ordem dos pontos importa ou usar permutação)
// Lógica: produto escalar de lados adjacentes deve ser 0 (90 graus) e lados opostos iguais.
bool isRectangle(point a, point b, point c, point d) {
    vec ab = toVec(a, b), bc = toVec(b, c), cd = toVec(c, d), da = toVec(d, a);
    return fabs(dot(ab, bc)) < EPS && fabs(dot(bc, cd)) < EPS && // Ângulos 90
           fabs(norm_sq(ab) - norm_sq(cd)) < EPS; // Lados opostos iguais
}

// 3. QUADRADO (SQUARE)
// Definição: Caso especial de retângulo onde width = height.
double areaSquare(double side) { return side * side; }
double perimeterSquare(double side) { return 4.0 * side; }

// 4. TRAPÉZIO (TRAPEZIUM)
// Definição: 4 arestas, 1 par de arestas paralelas.
// Se os lados não-paralelos são iguais -> Trapézio Isósceles.
// Área: (base_maior + base_menor) * altura / 2
double areaTrapezium(double base1, double base2, double h) {
    return 0.5 * (base1 + base2) * h;
}

// Verifica se é trapézio: AB paralelo a CD ou BC paralelo a DA
bool isTrapezium(point a, point b, point c, point d) {
    line l1, l2, l3, l4;
    pointsToLine(a, b, l1); pointsToLine(c, d, l2);
    pointsToLine(b, c, l3); pointsToLine(d, a, l4);
    return areParallel(l1, l2) || areParallel(l3, l4);
}

// 5. PARALELOGRAMO (PARALLELOGRAM)
// Definição: 4 arestas, lados opostos são paralelos.
// Todo retângulo é um paralelogramo.
// Área: base * altura (distância perpendicular entre bases)
double areaParallelogram(double base, double h) { return base * h; }

// 6. PIPA (KITE)
// Definição: Dois pares de lados de mesmo tamanho adjacentes.
// Área: (diagonal1 * diagonal2) / 2
double areaKite(double d1, double d2) { return 0.5 * d1 * d2; }

// 7. LOSANGO (RHOMBUS)
// Definição: Paralelogramo especial onde todos os lados são iguais.
// Também é um caso especial de Pipa.
// Área: Pode usar base*altura OU (d1*d2)/2
double areaRhombus(double d1, double d2) { return 0.5 * d1 * d2; }

// =========================================================
// [7.3.1] ALGORITHM ON POLYGON: REPRESENTAÇÃO
// =========================================================
typedef vector<point> polygon; 
// Nota: P[0] deve ser igual a P[n-1] para fechar o ciclo.

// =========================================================
// [7.3.2] ALGORITHM ON POLYGON: PERÍMETRO
// =========================================================
double perimeter(const polygon &P) {
    double result = 0.0;
    for (int i = 0; i < (int)P.size() - 1; i++) {
        result += dist(P[i], P[i+1]);
    }
    return result;
}

// =========================================================
// [7.3.3] ALGORITHM ON POLYGON: ÁREA
// Shoelace Formula: (x1y2 - x2y1) + (x2y3 - x3y2) ...
// =========================================================
double area(const polygon &P) {
    double result = 0.0;
    for (int i = 0; i < (int)P.size() - 1; i++) {
        result += (P[i].x * P[i+1].y - P[i+1].x * P[i].y);
    }
    return fabs(result) / 2.0;
}

// =========================================================
// [7.3.4] CHECKING IF POLYGON IS CONVEX
// Todos os giros devem ser na mesma direção (CCW ou CW).
// =========================================================
bool isConvex(const polygon &P) {
    int sz = (int)P.size();
    if (sz <= 3) return false;
    bool isLeft = ccw(P[0], P[1], P[2]);
    for (int i = 1; i < sz - 1; i++) {
        if (ccw(P[i], P[i+1], P[(i+2) == sz ? 1 : i+2]) != isLeft)
            return false;
    }
    return true;
}

// =========================================================
// [7.3.5] CHECKING IF POINT IS INSIDE POLYGON
// Método: Winding Number (Soma de ângulos).
// Funciona para Côncavos e Convexos.
// =========================================================
bool inPolygon(point pt, const polygon &P) {
    if ((int)P.size() == 0) return false;
    double sum = 0;
    for (int i = 0; i < (int)P.size() - 1; i++) {
        if (ccw(pt, P[i], P[i+1])) sum += angle(P[i], pt, P[i+1]);
        else sum -= angle(P[i], pt, P[i+1]);
    }
    return fabs(fabs(sum) - 2*PI) < EPS;
}

// =========================================================
// [7.3.6] CUTTING POLYGON WITH A STRAIGHT LINE
// Sutherland-Hodgman: Retorna lado ESQUERDO da linha a->b
// =========================================================
polygon cutPolygon(point a, point b, const polygon &Q) {
    polygon P;
    for (int i = 0; i < (int)Q.size(); i++) {
        double left1 = cross(toVec(a, b), toVec(a, Q[i]));
        double left2 = 0;
        if (i != (int)Q.size() - 1) left2 = cross(toVec(a, b), toVec(a, Q[i+1]));
        if (left1 > -EPS) P.push_back(Q[i]);
        if (left1 * left2 < -EPS) {
            point intersect_pt;
            line l1, l2;
            pointsToLine(a, b, l1);
            pointsToLine(Q[i], Q[i+1], l2);
            areIntersect(l1, l2, intersect_pt);
            P.push_back(intersect_pt);
        }
    }
    if (!P.empty() && !(P.back() == P.front())) P.push_back(P.front());
    return P;
}

// =========================================================
// [7.3.7] CONVEX HULL (GRAHAM SCAN)
// Encontra o polígono envolvente mínimo.
// =========================================================
point pivot;
bool angleCmp(point a, point b) {
    if (fabs(cross(toVec(pivot, a), toVec(pivot, b))) < EPS)
        return dist(pivot, a) < dist(pivot, b);
    double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
}

vector<point> CH(vector<point> P) {
    int i, j, n = (int)P.size();
    if (n <= 3) {
        if (!(P[0] == P[n-1])) P.push_back(P[0]);
        return P;
    }
    int P0 = 0;
    for (i = 1; i < n; i++)
        if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
            P0 = i;
    point temp = P[0]; P[0] = P[P0]; P[P0] = temp;
    pivot = P[0];
    sort(++P.begin(), P.end(), angleCmp);
    vector<point> S;
    S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]);
    i = 2;
    while (i < n) {
        j = (int)S.size() - 1;
        if (ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]);
        else S.pop_back();
    }
    return S;
}

vector<point> CH_Monotone(vector<point> &P) {
    int n = P.size(), k = 0;
    if (n <= 2) return P;
    
    vector<point> H(2 * n);

    sort(P.begin(), P.end());

    for (int i = 0; i < n; ++i) {
        while (k >= 2 && cross(toVec(H[k-2], H[k-1]), toVec(H[k-2], P[i])) <= 0) k--;
        H[k++] = P[i];
    }

    for (int i = n - 2, t = k + 1; i >= 0; i--) {
        while (k >= t && cross(toVec(H[k-2], H[k-1]), toVec(H[k-2], P[i])) <= 0) k--;
        H[k++] = P[i];
    }

    H.resize(k - 1);
    return H;
}
