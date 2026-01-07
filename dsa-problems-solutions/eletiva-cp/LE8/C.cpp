#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using ll = long long;

const ll INF = 1e18;

void solve(){
    int n, a, b; cin >> n >> a >> b;
    vector<double> dp(6 * n + 1, 0.0);

    dp[0] = 1.0;

    for (int i = 1; i <= n; ++i){
        vector<double> ndp(6 * n + 1, 0.0);

        for (int j = 1; j <= 6 * i; ++j){
            for (int k = 1; k <= 6; ++k){
                if (j - k >= 0){
                    ndp[j] += dp[j-k]/6.0;
                }
            }
        }
        dp = ndp;
    }

    double ans = 0.0;
    for (int i = a; i <= b; ++i) ans += dp[i];
    cout << fixed << setprecision(6) << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //int tt; cin >> tt; while(tt--) solve();
    solve();


}
