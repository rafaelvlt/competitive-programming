#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin >> n;
    string _, t;
    map<string, int> poss;
    for (int i = 0; i < n; i++){
        cin >> _ >> t;
        poss[t] += 1;
    }
    int ans = 1;
    for (auto it = poss.begin(); it != poss.end(); it++){
        ans *= (it->second+1);
    }
    cout << ans-1;
}

int main(){
    int tt; cin >> tt; while(tt--) {
        solve();
        if (tt != 0) cout << '\n';
    }
}
