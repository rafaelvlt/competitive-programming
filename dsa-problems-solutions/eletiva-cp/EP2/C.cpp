#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int n ; cin >> n;
    ll x; cin >> x;
    map<ll, vector<int>> v;
    for(int i = 1; i <= n ; i++){ 
        ll a; cin >> a;
        v[a].push_back(i);
    }
    ll f = -1;
    ll s = -1;
    for (auto it = v.begin(); it != v.end(); it++){
        ll diff = 0;
        if (it->first > x) continue;
        else if (it->first < x) diff = x - it->first;

        auto itS = v.find(diff);
        if (itS != v.end()){
            if (it != itS){
            f = it->second.at(0);
            s = itS->second.at(0);
            break;
            }
            else if (it->second.size() > 1){
                f = min(it->second.at(1), it->second.at(0));
                s = max(it->second.at(1), it->second.at(0));
                break;
            }
        }
    }
    if (f == -1 && s == -1) cout << "IMPOSSIBLE";
    else cout << f << " " << s;

    /* 
    possibilidades:
    os dois estão no array e são distintos: check
    os dois estão no array e são iguais: check
    os dois não estão no array: check;
    */
}

int main(){

    solve();
    //int tt; cin >> tt; while(tt--) solve();
}