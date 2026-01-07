#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using ll = long long;

const ll INF = 1e18;

struct Edge {
    int to;     
    ll cap;     
    ll flow;    
    int rev;    
};

void add_edge(int u, int v, ll cap, vector<vector<Edge>>& AdjList) {
    Edge fwd = {v, cap, 0, (int)AdjList[v].size()};
    Edge bwd = {u, 0,   0, (int)AdjList[u].size()};
    AdjList[u].push_back(fwd);
    AdjList[v].push_back(bwd);
}

bool bfs_karp(int s, int t, int V, vector<vector<Edge>>& AdjList, vector<int>& p, vector<Edge*>& p_edge) {
    
    fill(p.begin(), p.end(), -1);
    fill(p_edge.begin(), p_edge.end(), nullptr);
    
    p[s] = s;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == t) return true; 

        for (auto &e : AdjList[u]) {
            int v = e.to;
            if (p[v] == -1 && e.cap > e.flow) {
                p[v] = u;         
                p_edge[v] = &e;   
                q.push(v);
            }
        }
    }
    return false; 
}

void getMinCutDFS(int u, vector<bool>& visited, vector<vector<Edge>>& AdjList) {
    visited[u] = true;
    for (auto& e : AdjList[u]) {
        if (e.cap > e.flow && !visited[e.to]) {
            getMinCutDFS(e.to, visited, AdjList);
        }
    }
}


void solve(){
    int n, m; cin >> n >> m;

    vector<vector<Edge>> AdjList(n);    

    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        add_edge(a, b, 1, AdjList);
        add_edge(b, a, 1, AdjList);
    }

    ll mf = 0; 

    vector<int> p(n);
    vector<Edge*> p_edge(n);

    int s, t;
    s = 0; t = n-1;
    while (bfs_karp(s, t, n, AdjList, p, p_edge))
    {

        ll path_flow = INF;
        for (int v = t; v != s; v = p[v])
        {
            path_flow = min(path_flow, p_edge[v]->cap - p_edge[v]->flow);
        }

        for (int v = t; v != s; v = p[v])
        {
            p_edge[v]->flow += path_flow;

            Edge &rev_edge = AdjList[v][p_edge[v]->rev];
            rev_edge.flow -= path_flow;
        }

        mf += path_flow; 
    }


    cout << mf << '\n';

    vector<bool> vis(n, false);
    getMinCutDFS(s, vis, AdjList);
    vector<int> S;

    for (int i = 0; i < n; i++){
        if (vis[i]) S.push_back(i);
    }
    
    for (int& a : S){
        for (int i = 0; i < AdjList[a].size(); i++){
            if (vis[AdjList[a][i].to] == false && AdjList[a][i].cap > 0){
                cout << a+1 << " " << AdjList[a][i].to + 1 << '\n';
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; while(tt--) solve();
    solve();
}
