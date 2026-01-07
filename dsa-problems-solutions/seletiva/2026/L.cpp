#include <bits/stdc++.h>

using namespace std;


using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

void solve(){
    ll n, k; cin >> n >> k;
    vll arr(n);
    cin >> arr[0];
    ll a, b, c; cin >> a >> b >> c; 
    for (int i = 1; i < n; i++){
        arr[i] = (a * arr[i-1] + b) % c;
    }

    vll psum(n+1, 0);
    for (int i = 0; i < n; i++){
        psum[i+1] = arr[i] + psum[i];
    }

    ll l = 0;
    ll r = k-1;
    ll xors = 0;
    for(l = 0; r < n; l++, r++){
        xors ^= psum[r+1] - psum[l];
    }
    cout << xors;
}

int main(){
    
    //int tc; cin >> tc; while(tc--) solve();
    solve();
}