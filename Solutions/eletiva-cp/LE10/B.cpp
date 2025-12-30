#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using ll = long long;

const ll INF = 1e18;
const double EPS = 1e-9;

struct point
{
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}
};

struct vec
{
    double x, y;
    vec(double _x, double _y) : x(_x), y(_y) {}
};

double dist(point p1, point p2)
{
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

vec toVec(point a, point b) { return vec(b.x - a.x, b.y - a.y); }
vec scale(vec v, double s) { return vec(v.x * s, v.y * s); }
point translate(point p, vec v) { return point(p.x + v.x, p.y + v.y); }
double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }
double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

double distToLine(point p, point a, point b)
{
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    point c = translate(a, scale(ab, u));
    return dist(p, c);
}

struct City
{
    string name;
    point coords;
    double d;
};

void solve()
{

    point h1, h2;
    cin >> h1.x >> h1.y >> h2.x >> h2.y;

    int m;
    cin >> m;
    vector<City> cities(m);

    double min_dist = 1e18;

    for (int i = 0; i < m; i++)
    {
        cin >> cities[i].name >> cities[i].coords.x >> cities[i].coords.y;

        cities[i].d = distToLine(cities[i].coords, h1, h2);

        if (cities[i].d < min_dist)
        {
            min_dist = cities[i].d;
        }
    }

    bool first = true;
    for (int i = 0; i < m; i++)
    {
        if (fabs(cities[i].d - min_dist) < EPS)
        {
            if (!first)
                cout << " ";
            cout << cities[i].name;
            first = false;
        }
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--)
        solve();
    // solve();
}
