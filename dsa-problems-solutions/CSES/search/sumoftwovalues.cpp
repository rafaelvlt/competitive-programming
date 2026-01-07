#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> A(n);
    for (int i = 0; i < n ; ++i) cin >> A[i];
    
    bool found = false;
    for (int i = 0; i < n; ++i) {
        for (int j = (int)A.size()-1; j >= 0; --j){
            if (i != j && (A[i] + A[j]) == x) {
                cout << i+1 << " " << j+1 << '\n';
                found = true;
                break;
            }
        }
        if (found) break;
    }
    if (!found){
        cout << "IMPOSSIBLE";
    }
}
