#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using ll = long long;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    
    vector<string> words(n);
    for (int i = 0; i < n; i++)
        cin >> words[i];
    
    string t;
    cin >> t;
    
    int len = t.length();
    vll dp(len + 1, 0);
    dp[0] = 1;
    
    for (int i = 1; i <= len; i++){
        for (const string& w : words){
            int wlen = w.length();
            
            if (i >= wlen){
                int j = i - wlen;
                bool match = true;
                
                for (int k = 0; k < wlen; k++){
                    if (t[j + k] != '?' && t[j + k] != w[k]){
                        match = false;
                        break;
                    }
                }
                
                if (match)
                    dp[i] = (dp[i] + dp[j]) % MOD;
            }
        }
    }
    
    cout << dp[len] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //int tt; cin >> tt; while(tt--) solve();
    solve();
}



