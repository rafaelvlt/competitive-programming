#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using ll = long long;

const ll INF = 1e18;

ll dp[5000][5000];

void solve(){
    int n, m;
    ll a, b, c;
    cin >> n >> m >> a >> b >> c;
    
    string s, t;
    cin >> s >> t;
    
    for (int i = 0; i <= n; i++) dp[i][0] = i * b;
    for (int i = 0; i <= m; i++) dp[0][i] = i * a;
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                ll remove_op = dp[i-1][j] + b;
                ll add_op = dp[i][j-1] + a;
                ll sub_op = dp[i-1][j-1] + c;
                dp[i][j] = min({remove_op, add_op, sub_op});
            }
        }
    }
    
    cout << dp[n][m] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //int tt; cin >> tt; while(tt--) solve();
    solve();
}

