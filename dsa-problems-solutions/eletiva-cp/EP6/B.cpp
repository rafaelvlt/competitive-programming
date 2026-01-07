#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using ll = long long;

vector<vector<int>> adjList;
vector<bool> visited;
int n, m;
vector<vector<int>> paths;
vector<int> ans;
int idx = 0;

void dfs(int u) {

    visited[u] = true;
    paths[idx].push_back(u);
    for (int j = 0; j < (int)adjList[u].size(); j++) { 
        int v = adjList[u][j];
        if (visited[v] == false)
            dfs(v);
    }
} 

int main(){
    cin >> n >> m;
    adjList.resize(n);
    visited.resize(n);
    visited.assign(n, false);
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        adjList[a].push_back(b); adjList[b].push_back(a);
    }
    bool end = false;
    while(!end){
        end = true;
        for (int i = 0; i < n; i++){
            if (visited[i] == false){
                paths.push_back({});
                dfs(i);
                idx++;
            }
        }
    }
    if (idx > 1){
        cout << idx-1 << '\n';
        for (int i = 0; i < idx-1; i++){
            cout << paths[i].back() + 1 << " " << paths[i+1].back() + 1 << '\n';
        }
    }
    else cout << 0 << '\n';
}