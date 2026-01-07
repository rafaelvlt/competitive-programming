#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using ll = long long;

const ll INF = 1e18;

void solve(){
    string t, p;
    cin >> t >> p;
    
    int n = t.length();
    int m = p.length();
    
    if (m == 0){
        cout << 0 << '\n';
        return;
    }
    
    vi fail(m + 1);
    int i = 0, j = -1;
    fail[0] = -1;
    
    while (i < m){
        while (j >= 0 && p[i] != p[j])
            j = fail[j];
        i++;
        j++;
        fail[i] = j;
    }
    
    i = 0;
    j = 0;
    int ans = 0;
    
    while (i < n){
        while (j >= 0 && t[i] != p[j])
            j = fail[j];
        i++;
        j++;
        
        if (j == m){
            ans++;
            j = fail[j];
        }
    }
    
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //int tt; cin >> tt; while(tt--) solve();
    solve();
}
