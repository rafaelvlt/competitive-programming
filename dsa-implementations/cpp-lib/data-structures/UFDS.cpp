#include <bits/stdc++.h>

using namespace std;

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