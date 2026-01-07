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

int main() {
    std::vector<int> my_data = {5, 8, 6, 3, 2, 7, 2, 6};

    // Instancie o objeto. O construtor faz todo o trabalho de alocação e build.
    SegmentTree seg_tree(my_data);

    // Use os métodos do objeto para interagir com a árvore.
    cout << "Soma do intervalo [3, 7): " << seg_tree.query(3, 7) << endl; 

    cout << "Modificando o elemento no indice 3 para o valor 1..." << endl;
    seg_tree.set(3, 1);

    cout << "Nova soma do intervalo [3, 7): " << seg_tree.query(3, 7) << endl;

    vector<int> other_data = {10, 20, 30};
    SegmentTree other_seg_tree(other_data);
    cout << "Soma da outra arvore [0, 3): " << other_seg_tree.query(0, 3) << std::endl;

    return 0;
}
