#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

void KB()
{
    int SC = 0;
    int N;
    cin >> N;
    int* A = new int[2*N];

    for (int i = 0; i < 2*N; ++i) cin >> A[i];

    sort(A, A+(2*N));
    for (int i = 0; i < 2*N; i += 2)
    {
        SC +=  min(A[i], A[i+1]);
    }

    delete[] A;
    cout << SC << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int TC;
    cin >> TC;
    while (TC--)
    {
        KB();
    }

}
