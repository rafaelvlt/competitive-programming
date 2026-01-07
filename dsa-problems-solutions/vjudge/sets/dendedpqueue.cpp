#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    multiset<ll> s;
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; ++i){
        ll b; cin >> b;
        s.insert(b);
    }

    for (int i = 0; i < q; ++i ){
        int opt; cin >> opt;
        if (opt == 0){
            ll x; cin >> x;
            s.insert(x);
        }
        else if (opt == 1){
            auto lw = s.begin();
            cout << *lw << '\n';
            s.erase(lw);
        }
        else if(opt == 2){
            auto hi = s.end();
            --hi;
            cout << *(hi) << '\n';
            s.erase(hi);
        }
    }
}
