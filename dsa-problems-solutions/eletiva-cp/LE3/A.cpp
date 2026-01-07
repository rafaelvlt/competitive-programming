#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct SegmentTree {
private:
    int size;
    vector<ll> tree;

    void build() {
        for (int i = size - 1; i > 0; --i) {
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
        }
    }

public:
    // construtor
    SegmentTree(const std::vector<ll>& initial_data) {
        // tamanho baseado no array de entrada
        size = initial_data.size();
        
        tree.resize(2 * size);
        
        for (int i = 0; i < size; ++i) {
            tree[size + i] = initial_data[i];
        }
        
        build();
    }


    void set(int p, ll value) {
        for (tree[p += size] = value; p > 1; p >>= 1) {
            tree[p >> 1] = tree[p] + tree[p ^ 1];
        }
    }

    ll query(int l, int r) {
        ll res = 0;
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += tree[l++];
            if (r & 1) res += tree[--r];
        }
        return res;
    }
};



int main(){
    int n, q; cin >> n >> q;
    vector<ll> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    SegmentTree st(A);

    while(q--){
        int t, k, u;
        cin >> t >> k >> u;
        if (t == 1){
            st.set(k-1, u);
        }
        if (t == 2){
            ll ans = st.query(k-1, u);
            cout << ans << '\n';
        }
    }

    return 0;
}
