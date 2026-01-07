#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int S;
    cin >> S;
    int* A = new int[S];

    for (int i = 0; i < S; ++i) cin >> A[i];

    sort(A, A + S);

    auto l = unique(A, A + S);
    
    int tamanho = l - A;

    cout << tamanho;
    
    delete[] A;
    A = nullptr;

    return 0;
}

