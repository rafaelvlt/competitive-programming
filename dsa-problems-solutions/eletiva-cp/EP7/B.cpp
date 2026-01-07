#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using ll = long long;

const ll INF = 1e18;

void solve(){
    int n, m, q; cin >> n >> m >> q;

    vector<vector<ll>> AdjMat(n, vector<ll>(n, INF));
    for (int i = 0; i < n; i++){
        AdjMat[i][i] = 0;
    }

    for (int i = 0; i < m; i++){
            int a, b;
            ll w;
            cin >> a >> b >> w;
            a--; b--;
            AdjMat[a][b] = min(AdjMat[a][b], w);
            AdjMat[b][a] = min(AdjMat[a][b], w);
    }
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (AdjMat[i][k] == INF || AdjMat[k][j] == INF) continue;

                if (AdjMat[i][k] + AdjMat[k][j] < AdjMat[i][j]) {
                    AdjMat[i][j] = AdjMat[i][k] + AdjMat[k][j]; 
                }
            }
        }
    }

    for (int i = 0; i < q; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        if (AdjMat[a][b] != INF) cout << AdjMat[b][a] << '\n';
        else cout << -1 << '\n';
    }


}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //int tt; cin >> tt; while(tt--) solve();
    solve();
}

