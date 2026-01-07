#include <bits/stdc++.h>

using namespace std;

// permutação recursiva =============
int n;
vector<int> permutation;
vector<bool> chosen;
void search(){
    //permutações do set 0, 1... n-1
    vector<int> permutation;
    if (permutation.size() == n) {
        // process permutation
    } else {
        for (int i = 0; i < n; i++) {
            // se o caso i já foi escolhido, pula
            if (chosen[i]) continue;
            //escolhe o numero i e chama recursivamente
            chosen[i] = true;
            permutation.push_back(i);
            search();
            // retira a escolha do numero i e chama recursivamente
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}
// ====================================

// permutação com STL =============
void solve(){
    
    int n; cin >> n;
    vector<int> permutation;
    for (int i = 0; i < n; i++) {
    permutation.push_back(i);
    }
    do {
    // process permutation
    } while (next_permutation(permutation.begin(),permutation.end()));
}
// ====================================
