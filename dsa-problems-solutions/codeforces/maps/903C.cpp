#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int n; cin >> n;
    ll lar = 0;
    map<ll, ll> m;
    for (int i = 0; i < n; ++i){
        ll b; cin >> b;
        m[b] += 1;

    }

    for (auto it = m.begin(); it != m.end(); it++){
            ll vazias = it->second;
            for (auto itl = m.begin() ; itl != it; itl++){
                if (vazias > 0){
                    ll d = min(itl->second, vazias);
                    itl->second -= d;
                    vazias -= d;
                }
                else break;
            }
        }
    int ans = 0;
    for (auto p : m){
        ans += p.second;
    }
    cout << ans << '\n';
}
