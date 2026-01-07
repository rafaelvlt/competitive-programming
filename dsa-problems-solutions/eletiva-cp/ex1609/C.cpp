#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;

    int* A = new int[N];

    for (int i = 0; i < N ; ++i)
    {
        cin >> A[i];
    }
    int V;
    for (int j = 0; j < Q ; ++j)
    {
        cin >> V;
        auto I = lower_bound(A, A + N, V);

        if (I != (A+N) && *I == V) cout << (I - A) << '\n';
        else cout << -1 << '\n';
    }

    delete[] A;

    return 0;
}
