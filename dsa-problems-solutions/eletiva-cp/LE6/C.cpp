#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using ll = long long;

vector<vector<int>> adjList;

vector<bool> dfs_num;
vector<int> path;
bool cycle = false;

void dfs(int u, int parent) {
    dfs_num[u] = true;
    path[u] = v;
    for (int j = 0; j < (int)adjList[u].size(); j++) {
        int v = adjList[u][j];
        if (dfs_num[v] == false && !cycle)
            dfs(v, u);
        else{
            if (dfs_num[v] != parent){
                cycle = true;
            }
        }
    }
}


int main(){
    int n, m; cin >> n >> m;
    adjList.resize(n);
    dfs_num.resize(n);
    path.resize(n);
    dfs_num.assign(n, false);
    for (int i = 0; i < m ; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        adjList[a].push_back(b); adjList[b].push_back(a);
    }
    dfs(0, -1);
}