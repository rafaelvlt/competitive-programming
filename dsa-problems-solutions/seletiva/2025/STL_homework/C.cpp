#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vector<ll> A;
    multiset<ll> B;

    for (int i = 0; i < n; ++i){
        ll a; cin >> a;
        A.push_back(a);
    }
    for (int i = 0; i < n-1; ++i){
        ll b; cin >> b;
        B.insert(b);
    }
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    vector<ll> ans;
    for (auto it = A.begin(); it != A.end(); ++it){
        auto pos = B.lower_bound(*it);
        if (*it == *pos){
            B.erase(pos);
        }
        else{
            pos = B.upper_bound(*it);
            if (pos != B.end()){
                B.erase(pos);
            }
            else ans.push_back(*it);
        }
    }

    if (ans.size() > 1) cout << -1 << '\n';
    else{
        cout << ans[0] << '\n';
    } 

}
