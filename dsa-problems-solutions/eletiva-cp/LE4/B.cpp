#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


void solve(){
    int n; cin >> n;
    vector<ll> original_set(n);
    for (int i = 0; i < n; i++) cin >> original_set[i];
    ll totalSum = accumulate(original_set.begin(), original_set.end(), 0LL);
    int power_set_size = 1 << n;
    vector<ll> sums(power_set_size);
    for (int i = 0; i < power_set_size; i++) {
        ll sum = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                sum += original_set[j];
            }
        }
        sums[i] = sum;
    }
    
    ll ans = 999'999'999'999'999'999;
    for (ll sum : sums){
        ans = min(ans, abs(sum  - (totalSum - sum)));       
    }
    cout << ans;

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();
    //int tt; cin >> tt; while(tt--) solve();
    
}
