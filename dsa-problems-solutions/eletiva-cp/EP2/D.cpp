#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n, k; cin >> n >> k;
    vector<ll> A(n);
    for (ll& a : A) cin >> a;

    //n(n+1)/2 = sum

    for (int i = 0; i < n; i++){
        vector<ll> temp(k);
        ll c = -1;
        for (int j = 0; j < k; j++){
            temp.push_back(A[i+j]);
            c = min(A[i+j], c);
        }
        

    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}