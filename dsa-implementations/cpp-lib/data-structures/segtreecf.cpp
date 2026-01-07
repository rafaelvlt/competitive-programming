#include <stdio.h>

const int N = 1e5;
int n;
int t[2 * N];

// para alterar operações para min ou max, basta trocar o +
// das funções para min() ou max() (não esquecer de mudar o res = 0 para res = inf)

void build() {
    for (int i = n - 1; i > 0; --i){
        t[i] = t[i << 1] + t[i<<1 | 1];
    }
}
//position p becomes value
void set(int p, int value) {
    for (t[p += n] = value; p > 1; p >>= 1){
        t[p>>1] = t[p] + t[p^1];
    }
}

int query(int l, int r){
    int res = 0;
    for (l += n, r += n; l < r; l >>=1, r>>=1){
        if (l&1) res += t[l++];
        if (r&1) res += t[--r];
    }
    return res;
}

int main()  {
    scanf("%d", &n);
    //pega input das folhas
    for (int i = 0; i < n; ++i) scanf("%d", t + n + i);
    build();
    set(0, 1);
    printf("%d\n", query(3, 11));
}


//query para um elemento na posição p
int query(int p) {
  int res = 0;
  for (p += n; p > 0; p >>= 1) res += t[p];
  return res;
}

//adicionar um valor para todos elementos do intervalo
void modify(int l, int r, int value) {
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) t[l++] += value;
    if (r&1) t[--r] += value;
  }
}

// pós modificação acima, empurra tudo para as folhas serem alteradas também
// permitindo inspencionar tranquilamente
void push() {
  for (int i = 1; i < n; ++i) {
    t[i<<1] += t[i];
    t[i<<1|1] += t[i];
    t[i] = 0;
  }
}
