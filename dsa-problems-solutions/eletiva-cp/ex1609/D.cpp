#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    string A;
    string B;
    int S;
    for (int i = 0; i < T; ++i)
    {
        cin >> A;
        B = A;
        S = A.length();
        for (int j = 0; j < S ; ++j)
        {
            if (A[S - 1 - j] == 'p') B[j] = 'q';
            else if (A[S - 1 - j] == 'q') B[j] = 'p';
            else B[j] = 'w'; 
        }
        cout << B << '\n';
    }

    return 0;
}

