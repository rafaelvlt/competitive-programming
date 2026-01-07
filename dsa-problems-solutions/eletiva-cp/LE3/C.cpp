#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
private:
    int size;
    vector<int> tree;

    void build() {
        for (int i = size - 1; i > 0; --i) {
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
        }
    }

public:
    // construtor
    SegmentTree(const std::vector<int>& initial_data) {
        // tamanho baseado no array de entrada
        size = initial_data.size();
        
        tree.resize(2 * size);
        
        for (int i = 0; i < size; ++i) {
            tree[size + i] = initial_data[i];
        }
        
        build();
    }


    void set(int p, int value) {
        for (tree[p += size] = value; p > 1; p >>= 1) {
            tree[p >> 1] = tree[p] + tree[p ^ 1];
        }
    }

    int query(int l, int r) {
        int res = 0;
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += tree[l++];
            if (r & 1) res += tree[--r];
        }
        return res;
    }
};

void solve(){
    int n; cin >> n;
    

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tt; cin >> tt; while(tt--) solve();
    
    return 0;
}
