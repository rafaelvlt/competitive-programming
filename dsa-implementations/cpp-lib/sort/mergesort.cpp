#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/**
 * @brief Implementação do Merge Sort.
 * @param v O vetor a ser ordenado (será modificado).
 * @complexity O(N log N) em tempo e O(N) em espaço auxiliar.
 */
void mergeSort(vector<int>& v) {
    int n = v.size();
    if (n <= 1) return;

    vector<int> left(v.begin(), v.begin() + n / 2);
    vector<int> right(v.begin() + n / 2, v.end());

    mergeSort(left);
    mergeSort(right);

    int i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) v[k++] = left[i++];
        else v[k++] = right[j++];
    }
    while (i < left.size()) v[k++] = left[i++];
    while (j < right.size()) v[k++] = right[j++];
}

/**
 * @brief Conta o número de inversões em um vetor usando Merge Sort modificado.
 * @param v O vetor (será ordenado como efeito colateral).
 * @return O número de inversões.
 * @complexity O(N log N)
 */
ll countInversions(vector<int>& v) {
    int n = v.size();
    if (n <= 1) return 0;
    ll inversions = 0;

    vector<int> left(v.begin(), v.begin() + n / 2);
    vector<int> right(v.begin() + n / 2, v.end());

    inversions += countInversions(left);
    inversions += countInversions(right);

    int i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            v[k++] = left[i++];
        } else {
            v[k++] = right[j++];
            // AQUI ESTÁ A MUDANÇA: Se pegamos um elemento da direita,
            // ele é menor que todos os elementos restantes na esquerda.
            inversions += (left.size() - i);
        }
    }
    while (i < left.size()) v[k++] = left[i++];
    while (j < right.size()) v[k++] = right[j++];
    
    return inversions;
}
