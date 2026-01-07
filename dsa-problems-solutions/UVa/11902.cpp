#include <bits/stdc++.h>

using namespace std;


void dfs(int u, vector<vector<int>>& adj, vector<bool>& visSrc, vector<bool>& vis, int dom=-1){
    if (dom == -1){
        visSrc[u] = true;
        for (int i = 0; i < adj[u].size(); i++ ){
            int v = adj[u][i];
            if (visSrc[v] == false){
                dfs(v, adj, visSrc, vis);
            }
        }
    }
    else{
        if (u != dom){
            vis[u] = true;
            for(int j = 0; j < adj[u].size(); j++) {
                int v = adj[u][j];
                if (vis[v] == false)
                    dfs(v, adj, visSrc, vis, dom);
            }
        }
    }
}

void printd(int n){
    cout << '+';
    for (int i = 0; i < n*2-1; i++) cout << '-';
    cout << "+\n";
}

void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(n);
    vector<bool> visSrc(n, false);
    vector<bool> vis(n, false);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int a; cin >> a;
            if (a) adj[i].push_back(j);
        }
    }    

    dfs(0, adj, visSrc, vis);

    for(int i = 0; i < n; i++){
        vis.assign(n, false);
        dfs(0, adj, visSrc, vis, i);
        printd(n);
        for (int j = 0; j < vis.size(); j++){
            cout << '|';
            if (visSrc[j] == false) cout << 'N';
            else {
                if (i==j) cout << 'Y';
                else if (vis[j] == false) cout << 'Y';
                else cout << 'N';
            }


            if (j == vis.size()-1) cout << "|\n";
        }

        if (i == n-1) printd(n);
    }

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int s = 1;
    int tt; cin >> tt; while(tt--){
        cout << "Case " << s << ":\n";
        solve();
        s++;
    }
}
