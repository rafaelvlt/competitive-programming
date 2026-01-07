#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

void solve(){
    ull l, r; cin >> l >> r;

    ull ans = l;

    for (int i = 0; i < 64; i++){
        // 1ULL é um 1 unsigned long long, tá movendo o bit LSB até a pos i
        ull temp = ans | (1ULL << i);

        if (temp <= r){
            ans = temp;
        }
    }
    cout << ans << '\n';
}

int main(){
    int tt; cin >> tt;
    while(tt--) solve();
}
