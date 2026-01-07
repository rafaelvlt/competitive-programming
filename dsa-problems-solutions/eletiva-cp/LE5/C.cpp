#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll inf = 100'000'000'000'000'000;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x; cin >> x >> n;
    int m = x + 3;
    vector<pair<int, ll>> v(n);
    for (int i = 0; i < n ; i++){
        cin >> v[i].first >> v[i].second;       
    }
    
    vector<ll> price(m+1, inf);
    price[0] = 0;   
    
    for (int i = 0; i < n; i++){
        int p = v[i].first;
        ll  c = v[i].second;

        for (int j = m; j >= p; j--){
            if (price[j - p] != inf){
                price[j] = min(price[j], price[j-p] + c);
            }
        }
    }
    ll ans = inf;
    for (int i = x; i <= m; ++i){
        ans = min(ans, price[i]);
    }

    if (ans == inf) cout << -1 << '\n';
    else cout << ans << '\n';
}
