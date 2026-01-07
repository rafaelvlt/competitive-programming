#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using ll = long long;


struct UnionFind{
    vector<int> parent;
    vector<int> size;

    UnionFind(int n){
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0); 
        size.assign(n, 1);
    }

    int find(int i){
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j)    {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j)   {
            if (size[root_i] < size[root_j]) swap(root_i, root_j);
            
            parent[root_j] = root_i;
            size[root_i] += size[root_j];
        }
    }

    int getSize(int i){
        return size[find(i)];
    }

    bool isSameSet(int a, int b){
        if (find(a) == find(b)) return true;
        else return false;
    }
};

int main(){
    int n, m; cin >> n >> m;

    vector<pair<int, pii>> edgeList;

    for (int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        edgeList.push_back(make_pair(c, make_pair(--a, --b)));
    }

    sort(edgeList.begin(), edgeList.end());

    long long  mst_cost = 0;
    UnionFind UF(n);
    int components = n;
    for (int i = 0; i < m; i++) {
        pair<int, pii> front = edgeList[i];
        if (!UF.isSameSet(front.second.first, front.second.second)) {
            mst_cost += front.first;
            UF.unite(front.second.first, front.second.second);
            components--;
        } 
    }
    
    if (components == 1) cout << mst_cost << '\n';
    else cout << "IMPOSSIBLE\n";
}