#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
// 1 por planeta ou c para todos
    int n, c; cin >> n >> c;
    map<int, int> orbits;
    for (int i = 0 ; i<n ; ++i){
        int p; cin >> p;
        orbits[p] += 1;
    }
    int ans = 0;
    for(auto it = orbits.begin(); it != orbits.end(); it++){
        bool machine = true; //true = 1st false = 2nd
        if (it->second > c) machine = false;
        
        if (machine) ans += it->second;
        else ans += c;
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //solve();
    int tt; cin >> tt; while(tt--) solve();
}