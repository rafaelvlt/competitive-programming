#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using ll = long long;

const ll INF = 1e18;

using ll = long long;

struct point {
    ll x, y;
};

struct vec {
    ll x, y;
    vec(ll _x, ll _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b) {
    return vec(b.x - a.x, b.y - a.y);
}

ll cross(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}

void solve() {
    point p1, p2, p3;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;

    vec v1 = toVec(p1, p2);
    vec v2 = toVec(p1, p3);

    ll cp = cross(v1, v2);

    if (cp > 0) cout << "LEFT\n"; 
    else if (cp < 0) cout << "RIGHT\n";
    else cout << "TOUCH\n";
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int tt; cin >> tt; while(tt--) solve();
    //solve();
}
