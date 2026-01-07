#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> A(n);
    vector<int> idx(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        idx[A[i]] = i;
    }
    int rounds = 0;
        

    cout << rounds << '\n';

}
