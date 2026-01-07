#include <bits/stdc++.h>

using namespace std;


using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

void solve(){
    int n; cin >> n;
    vll c(n);
    for (ll& k : c) cin >> k;
    vll p(n);
    for (ll& k : p) cin >> k;

    vll psum(n+1, 0);
    for (int i = 0; i < n; i++){
        psum[i+1] = psum[i] + p[i];
    }

    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        auto idxl = lower_bound(c.begin(), c.end(), l) - c.begin();
        auto idxr = lower_bound(c.begin(), c.end(), r) - c.begin();
        if (c[idxr] == r) cout << psum[idxr+1] - psum[idxl] << '\n';
        else cout << psum[idxr] - psum[idxl] << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    //int tc; cin >> tc; while(tc--) solve();
    solve();
}