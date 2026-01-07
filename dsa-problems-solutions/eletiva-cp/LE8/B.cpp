#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using ll = long long;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;

ll stol (string s, ll m){
    ll res = 0;
    for (char c : s) res = (res * 10 + (c - '0')) % m;
    return res;
}

void solve(){
    string s1, op, s2;
    cin >> s1 >> op >> s2;

    ll x = stol(s1, MOD);
    ll y;

    if (op == "^"){
        y = stol(s2, MOD - 1);
        ll ans = 1;
        x %= MOD;
        while (y > 0){
            if (y % 2 == 1) ans = (ans * x) % MOD;
            x = (x * x) % MOD;
            y /= 2;
        }

        cout << ans << '\n';
    }
    else{
        y = stol(s2, MOD);
        
        if (op == "+") cout << (x + y) % MOD << '\n';
        else if (op == "-") cout << (x - y + MOD) % MOD << '\n';
        else if (op == "*") cout << (x * y) % MOD << '\n';
    }
    
    
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //int tt; cin >> tt; while(tt--) solve();
    solve();
}
