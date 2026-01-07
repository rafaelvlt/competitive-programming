#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using ll = long long;

const ll INF = 1e18;

struct point {
    int x, y;
    bool operator < (point &other) {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};


void solve() {
    int n; cin >> n;

    set<int> row0;
    set<int> row1; 
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (y == 0) row0.insert(x);
        else row1.insert(x);
    }

    ll count = 0;

    for (int x : row0) {
        if (row1.count(x)) {
            count += (n - 2);
        }
    }

    for (int x : row0) {
        if (row1.count(x - 1) && row1.count(x + 1)) {
            count++;
        }
    }

     for (int x : row1) {
        if (row0.count(x - 1) && row0.count(x + 1)) {
            count++;
        }
    }

    cout << count << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int tt; cin >> tt; while(tt--) solve();
    //solve();
}
