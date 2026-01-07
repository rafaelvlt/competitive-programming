#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using ll = long long;

const ll INF = 1e18;

void solve(){
    string s;
    while (cin >> s && s != "."){
        if (s == "") cout << 0;
        else{
            string sub = "";
            for (int i = 1; i < s.size();i++){
                if (s.substr(0, i) == s.substr(i, i)){
                    sub = s.substr(0, i);
                    break;
                }
            }
            if (sub != "") cout << s.size()/sub.size() << "\n";
            else cout << 1 << '\n';
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //int tt; cin >> tt; while(tt--) solve();
    solve();
}
