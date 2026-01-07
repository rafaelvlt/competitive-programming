#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using ll = long long;

const double INF = 1e9;
// EPS: Tolerância para comparações de ponto flutuante (Evita erros de precisão)
const double EPS = 1e-9;
// PI: Valor preciso de PI
const double PI = acos(-1.0);

// Converte Graus para Radianos (Funções trigonométricas do C++ usam rad)
double DEG_to_RAD(double theta) { return theta * PI / 180.0; }

struct point {
    ll x, y;
    point() { x = y = 0.0; }
    point(ll _x, ll _y) : x(_x), y(_y) {}

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


struct vec { ll x, y; vec(ll _x, ll _y) : x(_x), y(_y) {} };

vec toVec(point a, point b) { return vec(b.x - a.x, b.y - a.y); }
ll cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

ll dist(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}
bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0;
}

point pivot;
bool angleCmp(point a, point b) {
    if (fabs(cross(toVec(pivot, a), toVec(pivot, b))) < EPS)
        return dist(pivot, a) < dist(pivot, b);
    ll d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    ll d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
}

vector<point> CH_Monotone(vector<point> &P) {
    int n = P.size(), k = 0;
    if (n <= 2) return P;
    
    vector<point> H(2 * n);

    sort(P.begin(), P.end());

    for (int i = 0; i < n; ++i) {
        while (k >= 2 && cross(toVec(H[k-2], H[k-1]), toVec(H[k-2], P[i])) < 0) k--;
        H[k++] = P[i];
    }

    for (int i = n - 2, t = k + 1; i >= 0; i--) {
        while (k >= t && cross(toVec(H[k-2], H[k-1]), toVec(H[k-2], P[i])) < 0) k--;
        H[k++] = P[i];
    }

    H.resize(k - 1);
    return H;
}


void solve(){
    int n; cin >> n;
    
    vector<point> A;
    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        A.push_back((point){x, y});
    }

    vector<point> ch = CH_Monotone(A);

    cout << ch.size() << '\n';
    for (int i = 0; i < ch.size(); i++){
        cout << ch[i].x << " " << ch[i].y << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //int tt; cin >> tt; while(tt--) solve();
    solve();
}
