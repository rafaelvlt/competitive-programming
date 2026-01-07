#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll n; cin >> n;
    set<ll> s;
    for(ll i = 2; i*i <= n; i++){
        ll x = i * i;
        while(x <= n){
            s.insert(x);
            x *= i;
        }
    }
    cout << n - s.size() << '\n';
}
