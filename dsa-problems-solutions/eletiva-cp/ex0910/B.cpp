#include <bits/stdc++.h>

using namespace std;

void solve(){
    int l, n; cin >> l >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];
    
    for (int i = 0; i < (1 << n); i++){
        int sum = 0;
        for (int j = 0; j < n; j++){
            if (i & (1 << j)) sum += b[j];
        }
        if (sum == l){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int tt; cin >> tt; while(tt--) solve();
}
