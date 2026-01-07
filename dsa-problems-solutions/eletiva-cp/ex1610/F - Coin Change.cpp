#include <bits/stdc++.h>

using namespace std;

int sols[7501][6];
int coins[5] = {50, 25, 10, 5, 1};

int search(int k, int t){
    if (k < 0) return 0;
    if (k == 0) return 1;
    if (t == 5) return 0;
    if (sols[k][t] != -1) return sols[k][t];

    sols[k][t] = search(k, t+1) + search(k - coins[t], t);
    return sols[k][t];
}

int main(){
    memset(sols, -1, sizeof(sols));
    int n;
    while(cin >> n){
        cout << search(n, 0) << '\n';
    }
}
