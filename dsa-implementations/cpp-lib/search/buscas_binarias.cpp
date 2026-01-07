#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
/**
 * @brief Encontra o primeiro índice 'i' tal que v[i] >= target.
 * Retorna v.size() se todos os elementos forem menores que o target.
 * Equivalente a std::lower_bound.
 * @param v Vetor ordenado.
 * @param target O valor a ser procurado.
 * @return O índice do primeiro elemento >= target.
 * @complexity O(log N)
 */
int lowerBound(const vector<int>& v, int target) {
    int lo = 0, hi = v.size(); // Busca no intervalo [lo, hi)
    int ans = v.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (v[mid] >= target) {
            ans = mid;
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}


/**
 * @brief Encontra a raiz de uma função f(x) em [lo, hi] usando o método da bissecção.
 * @param lo Limite inferior do intervalo.
 * @param hi Limite superior do intervalo.
 * @param f A função a ser avaliada. Requer que f(lo) e f(hi) tenham sinais opostos.
 * @return Uma aproximação da raiz de f(x).
 * @complexity O(log((hi-lo)/EPS))
 */
double bisection(double lo, double hi, function<double(double)> f) {
    // Define o número de iterações para alcançar a precisão desejada (1e-9 é comum)
    // log2((hi - lo) / 1e-9) iterações. 100 é um número seguro.
    for(int i = 0; i < 100; ++i) {
        double mid = lo + (hi - lo) / 2.0;
        if (f(mid) * f(lo) > 0) { // Se f(mid) tem o mesmo sinal de f(lo)
            lo = mid;
        } else {
            hi = mid;
        }
    }
    return lo; // Ou hi, estarão muito próximos
}


/**
 * @brief Template para "Busca Binária na Resposta" para encontrar um valor mínimo.
 * @param lo Limite inferior para a possível resposta.
 * @param hi Limite superior para a possível resposta.
 * @param check Função que retorna true se a resposta 'mid' é viável (e possivelmente melhorável).
 * @return A resposta mínima que satisfaz a condição.
 * @complexity O(C * log(hi-lo)), onde C é o custo da função check.
 */
ll binarySearchTheAnswer(ll lo, ll hi, function<bool(ll)> check) {
    ll ans = hi; // Inicializa com o pior caso (máximo)
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (check(mid)) { // Se 'mid' é uma resposta possível, tenta uma melhor (menor)
            ans = mid;
            hi = mid - 1;
        } else { // Se 'mid' não é possível, precisamos de uma resposta maior
            lo = mid + 1;
        }
    }
    return ans;
}
