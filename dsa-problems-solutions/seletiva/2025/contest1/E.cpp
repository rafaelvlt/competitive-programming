#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n ; cin >> n;
    vector<ll> A(n);
    for (ll& i : A) cin >> i;
    ll m = 0;
    for (int i = 1; i < n; i++){
        while (A[i] < A[i-1]){
            ++A[i];
            ++m;
        }  
    }
    cout << m;
}
