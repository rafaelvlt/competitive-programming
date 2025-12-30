/**
 * =========================================================
 * LIB GEOMETRIA COMPUTACIONAL - PARTE 2: POLÍGONOS
 * Baseado no Cap. 7.3 do livro Competitive Programming 3
 * Dependência: geometry_basic.h (point, vec, dist, cross, ccw, angle)
 * =========================================================
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

/**
 * =========================================================
 * 7.3.1 - REPRESENTAÇÃO DE POLÍGONO
 * =========================================================
 */
// Em competições, representamos polígonos como um vetor de pontos.
// Importante: O primeiro ponto deve ser repetido no final (P[0] == P[n-1])
// para fechar o ciclo e simplificar loops de perímetro/área.
typedef vector<point> polygon;

/**
 * =========================================================
 * 7.3.2 - PERÍMETRO DE UM POLÍGONO
 * =========================================================
 */
double perimeter(const polygon &P) {
    double result = 0.0;
    // Percorre até size()-1 pois o último ponto é igual ao primeiro
    for (int i = 0; i < (int)P.size() - 1; i++) {
        result += dist(P[i], P[i+1]);
    }
    return result;
}

/**
 * =========================================================
 * 7.3.3 - ÁREA DE UM POLÍGONO (Shoelace Formula)
 * =========================================================
 */
// Funciona para polígonos côncavos ou convexos.
// Retorna a área absoluta (positiva).
// Se remover o fabs, retorna positivo para CCW e negativo para CW.
double area(const polygon &P) {
    double result = 0.0;
    for (int i = 0; i < (int)P.size() - 1; i++) {
        // x1*y2 - x2*y1 (produto cruzado das coordenadas)
        result += (P[i].x * P[i+1].y - P[i+1].x * P[i].y);
    }
    return fabs(result) / 2.0;
}

/**
 * =========================================================
 * 7.3.4 - VERIFICAR SE POLÍGONO É CONVEXO
 * =========================================================
 */
// Um polígono é convexo se todos os giros consecutivos forem CCW ou todos CW.
// Assume que o polígono não é auto-intersectante.
bool isConvex(const polygon &P) {
    int sz = (int)P.size();
    if (sz <= 3) return false; // Ponto ou linha não é polígono convexo (no contexto de área)
    
    bool isLeft = ccw(P[0], P[1], P[2]); // Verifica a direção do primeiro giro
    for (int i = 1; i < sz - 1; i++) {
        // Se a direção mudar em algum momento, não é convexo
        if (ccw(P[i], P[i+1], P[(i+2) == sz ? 1 : i+2]) != isLeft)
            return false;
    }
    return true;
}

/**
 * =========================================================
 * 7.3.5 - PONTO DENTRO DO POLÍGONO (Point in Polygon - PIP)
 * =========================================================
 */
// Método: Winding Number (Soma dos ângulos)
// Retorna true se o ponto p está dentro do polígono P.
// Robusto para polígonos côncavos.
// Complexidade: O(N)
bool inPolygon(point p, const polygon &P) {
    if ((int)P.size() == 0) return false;
    double sum = 0;
    for (int i = 0; i < (int)P.size() - 1; i++) {
        // Se p for igual a algum vértice, consideramos dentro (ou borda)
        if (p == P[i]) return true; 
        
        // angle retorna valor em [0, PI]. Precisamos do sinal.
        // cross > 0 indica giro à esquerda (positivo), cross < 0 direita (negativo).
        if (ccw(p, P[i], P[i+1]))
             sum += angle(P[i], p, P[i+1]); // Soma ângulo positivo
        else sum -= angle(P[i], p, P[i+1]); // Subtrai ângulo negativo
    }
    // Se a soma for 2*PI (360 graus) ou -2*PI, o ponto está dentro.
    // Se for 0, está fora.
    return fabs(fabs(sum) - 2*PI) < EPS;
}
// 
/**
 * =========================================================
 * 7.3.6 - CORTAR POLÍGONO COM UMA RETA (Sutherland-Hodgman)
 * =========================================================
 */
// Corta o polígono Q pela reta definida pelos pontos A e B.
// Retorna a parte de Q que está à ESQUERDA da reta AB.
// Nota: Esta implementação assume que Q é convexo. O resultado também será convexo.
polygon cutPolygon(point a, point b, const polygon &Q) {
    polygon P;
    for (int i = 0; i < (int)Q.size(); i++) {
        // cross(AB, AP): > 0 (esquerda), < 0 (direita), 0 (colinear)
        double left1 = cross(toVec(a, b), toVec(a, Q[i]));
        double left2 = 0;
        
        // Verifica o próximo vértice (cuidado com o último índice)
        if (i != (int)Q.size() - 1) left2 = cross(toVec(a, b), toVec(a, Q[i+1]));
        
        // Se o ponto atual está à esquerda (dentro), mantemos ele
        if (left1 > -EPS) P.push_back(Q[i]);
        
        // Se a aresta Q[i]->Q[i+1] cruza a linha de corte
        // (um ponto na esquerda e outro na direita)
        if (left1 * left2 < -EPS) {
            point intersection;
            line l1, l2;
            pointsToLine(a, b, l1);           // Linha de corte
            pointsToLine(Q[i], Q[i+1], l2);   // Aresta do polígono
            areIntersect(l1, l2, intersection);
            P.push_back(intersection);
        }
    }
    // Fecha o polígono resultante se não estiver vazio
    if (!P.empty() && !(P.back() == P.front()))
        P.push_back(P.front());
    return P;
}
// 
/**
 * =========================================================
 * 7.3.7 - CONVEX HULL (Graham Scan)
 * =========================================================
 */
// Encontra o menor polígono convexo que contém todos os pontos de P.
// Complexidade: O(N log N) devido à ordenação.

// Variável global auxiliar para ordenação angular
point pivot_CH; 

// Comparador angular especial para o Graham Scan
// Retorna true se 'a' vem antes de 'b' no sentido anti-horário relativo ao pivot.
bool angleCmp(point a, point b) {
    if (collinear(pivot_CH, a, b))
        // Em caso de colinearidade, o ponto mais próximo do pivot deve ser processado primeiro?
        // Depende da implementação. Geralmente queremos o mais longe se for para descartar o meio.
        // Aqui, ordenamos por distância crescente para facilitar a remoção.
        return dist(pivot_CH, a) < dist(pivot_CH, b); 
        
    double d1x = a.x - pivot_CH.x, d1y = a.y - pivot_CH.y;
    double d2x = b.x - pivot_CH.x, d2y = b.y - pivot_CH.y;
    return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
}

vector<point> CH(vector<point> P) {
    int i, j, n = (int)P.size();
    if (n <= 3) {
        // Se já é um triângulo ou menos, retorna o próprio (fechado)
        if (!(P[0] == P[n-1])) P.push_back(P[0]);
        return P;
    }

    // 1. Encontrar o ponto com menor Y (e maior X em caso de empate Y) -> Pivot
    // O livro CP3 sugere menor Y e depois menor X, ou maior X. O importante é ser extremo.
    int P0 = 0;
    for (i = 1; i < n; i++)
        if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
            P0 = i;
            
    // Coloca o pivot na posição 0 do vetor
    point temp = P[0]; P[0] = P[P0]; P[P0] = temp;
    pivot_CH = P[0];

    // 2. Ordenar os pontos pelo ângulo polar em relação ao pivot
    // Note que P[0] é o pivot, então ordenamos de P[1] até o fim.
    sort(++P.begin(), P.end(), angleCmp);

    // 3. Executar o Graham Scan
    // Pilha S simulada com vector
    vector<point> S;
    S.push_back(P[n-1]); // Adiciona o último candidato (pode ser útil se colinear)
    S.push_back(P[0]);   // Adiciona Pivot
    S.push_back(P[1]);   // Adiciona primeiro ponto ordenado
    
    i = 2;
    while (i < n) {
        j = (int)S.size() - 1;
        // Verifica se o movimento S[j-1] -> S[j] -> P[i] é uma curva à esquerda (CCW).
        // Se for à direita ou colinear, removemos o topo da pilha (S[j]).
        if (ccw(S[j-1], S[j], P[i])) 
            S.push_back(P[i++]);
        else 
            S.pop_back();
    }
    return S; // Retorna os vértices do Convex Hull
}
/*
Explicação e Casos de Uso (Resumo da Seção 7.3)

1.  Representação: Lembre-se sempre de fechar o polígono (`P.push_back(P[0])`). Muitas funções acima assumem que `P[size-1] == P[0]`. Se o input do problema não der o polígono fechado, feche-o manualmente antes de chamar `area` ou `perimeter`.
2.  Área (Shoelace): A fórmula é extremamente poderosa. Note que se você não usar `fabs`, a área será negativa se os pontos estiverem em sentido horário (CW). Isso é útil para determinar a orientação de um polígono simples.
3.  Point in Polygon: O método da soma de ângulos (`angle` + `sum`) é lento ($O(N)$ com funções trigonométricas), mas é o mais seguro para polígonos complexos (côncavos). Se o polígono for estritamente convexo, você pode otimizar para $O(\log N)$ usando busca binária (não incluído aqui pois o CP3 foca no geral ou na simplicidade).
4.  Corte (Sutherland-Hodgman): Essencial para problemas como "Área de interseção". Cortar um polígono convexo repetidamente gera a região comum.
5.  Convex Hull (Graham Scan): O algoritmo clássico. Muito útil para problemas de "cerca", "diâmetro de conjunto de pontos" (usando Rotating Calipers após o CH) ou simplesmente para reduzir o espaço de busca de $N$ pontos para apenas os da borda.

Agora você tem a biblioteca completa baseada no Capítulo 7 (7.2 e 7.3).
*/
