#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n; cin >> n;
    map<ll, ll> B;
    for (int i = 0; i < n; ++i){
        ll b; cin >> b;
        B[b] += 1;
    }
    for (auto it = B.begin(); it != B.end(); it++ ){
        auto livres = it->second;
        for (auto itS = B.begin(); itS != it; itS++){
            if(livres > 0){
                ll menor = min(itS->second, livres);
                livres -= menor;
                itS->second -= menor;
            }
            else break;
        }
    }
    ll ans = 0;
    for (auto k : B) ans += k.second;
    cout << ans << '\n';
}

int main(){

    solve();
    //int tt; cin >> tt; while(tt--) solve();
}