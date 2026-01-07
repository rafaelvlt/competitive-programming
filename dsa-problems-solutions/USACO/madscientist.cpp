#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    string A, B; cin >> A >> B;
    int count = 0;
    int prevIdx = 0;
    int idx = 0;
    while( A != B){
        while(A[idx] == B[idx]){
            idx++;
            prevIdx = idx;
        }

        while(A[idx] != B[idx]) idx++;
        for (int i = prevIdx; i < idx; i++) B[i] = A[i];
        prevIdx = idx;
        count++;
    }
    cout << count;
}
