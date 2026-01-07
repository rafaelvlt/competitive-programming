#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct UnionFind{
    vector<int> parent;
    vector<int> size;

    UnionFind(int n){
        parent.resize(n+1);
        iota(parent.begin() + 1, parent.end(), 1); 
        size.assign(n+1, 1);
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
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    UnionFind uf(n);
    int r = 0;

    while (m--){
        int a, b; cin >> a >> b;
        if (uf.find(a) != uf.find(b)) {
            r++;
        }
        uf.unite(a, b);
    }

    ll ans = 1LL << r;
    
    cout << ans << '\n';

    return 0;
}
