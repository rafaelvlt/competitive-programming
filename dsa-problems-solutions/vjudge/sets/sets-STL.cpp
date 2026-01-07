#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int Q; cin >> Q;
    set<ll> s;
    for (int i =0; i < Q; i++){
        ll x; 
        int y; 
        cin >> y >> x;
        if (y == 1) s.insert(x);
        if (y == 2) s.erase(x);
        if (y == 3){
            if (s.find(x) != s.end()) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}
