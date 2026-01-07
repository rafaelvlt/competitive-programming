#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int n, m; cin >> n >> m;
    multiset<ll> tick;
    vector<ll> cust(m);
    for (int i = 0; i < n; ++i){
        ll b; cin >> b;
        tick.insert(b);
    }
    for (int i = 0;i<m;++i) cin >> cust[i];
    
    for (int i = 0; i<cust.size(); ++i){
        auto c = tick.upper_bound(cust[i]);
        if (c != tick.begin()){
            --c;
            cout << *c << '\n';
            tick.erase(c);
        }
        else{
            cout << -1 << '\n';
        }
    }
}
