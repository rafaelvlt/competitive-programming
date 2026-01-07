#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using ll = long long;

const ll INF = 1e18;

vector<int> getSP(int t, vector<int>& p) {

    vector<int> path;
    
    if (p[t] == -1 && t != p[0]) { 
        path.push_back(-1);
        return path;
    }

    for (int v = t; v != -1; v = p[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end()); 
    return path;
}

void solve(){

    int n, m; cin >> n >> m;
    vector<vector<pair<int, ll>>> adjList(n, vector<pair<int, ll>>());
    
    for (int i = 0; i < m; i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        --a; --b;
        adjList[a].push_back({b, w});
        adjList[b].push_back({a, w});
    }

    vector<ll> dist(n, INF);
    vector<int> p(n, -1);
    dist[0] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 0}); 

    while (!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Lazy Deletion 
        if (d > dist[u]) continue;

        for (auto& edge : adjList[u]) {
            int v = edge.first;
            ll w = edge.second; 

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w; 
                p[v] = u;              
                pq.push({dist[v], v}); 
            }
        }
    }

    vector<int> ans = getSP(n-1, p);
    
    for (int i = 0; i < ans.size(); i++){
        if (ans[i] != -1) cout << ans[i] + 1 << " ";
        else cout << ans[i];
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //int tt; cin >> tt; while(tt--) solve();
    solve();
}
