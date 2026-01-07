#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


bool check(ll mid, const vector<ll>& corals, int n, ll w)    {
    ll units = 0;
    for (int i = 0; i < n; i++){
        ll t = mid - corals[i];
        if (t > 0) units += t;
        
        if (units > w) return false;
    }
    return true;
}

void solve(){
    int n; cin >> n;
    ll w; cin >> w;
    vector<ll> corals(n);
    for (int i = 0; i < n; i++) cin >> corals[i];

    ll left = 1;
    ll right = 100'000'000'000;
    ll ans = 0;
    while (left <= right){
        ll mid = left + (right - left) / 2;
        if (check(mid, corals, n, w)){
            ans = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    //solve();
    int tt; cin >> tt; while(tt--) solve();
    
}
