#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using ll = long long;

const ll INF = 1e18;

int dp[5000][5000];

void solve(){
    string s1, s2;
    cin >> s1 >> s2;
    
    int n = s1.length();
    int m = s2.length();
    
    dp[0][0] = 0;
    
    for (int i = 1; i <= n; i++) dp[i][0] = i;
    
    for (int i = 1; i <= m; i++) dp[0][i] = i;
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min({dp[i-1][j-1] + 1, dp[i-1][j] + 1, dp[i][j-1] + 1});
        }
    }
    
    cout << dp[n][m] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //int tt; cin >> tt; while(tt--) solve();
    solve();
}

