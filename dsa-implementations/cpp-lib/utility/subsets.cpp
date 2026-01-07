#include <bits/stdc++.h>
using namespace std;

void bitMaskPowerSet{
    int n = original_set.size();    
    vector<vector<int>> power_set;
    int power_set_size = 1 << n;
    for (int mask = 0; mask < power_set_size; mask++) {
        for (int idx = 0; idx < n; idx++) {
            if (mask & (1 << idx)) {
                power_set[mask].push_back(original_set[idx]);
            }
        }
    }
}

//gera o subset de 0 até n, com k sendo chamado com 0 primeiro
//idealmente fazer um subsets globais e dar pushback
int n;
vector<int> subset;
void search(int k) {
    if (k == n) {
        // process subset
    } else {
    search(k+1);
    subset.push_back(k);
    search(k+1);
    subset.pop_back();
    }
}
