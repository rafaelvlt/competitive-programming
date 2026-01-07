#include <bits/stdc++.h>

using namespace std;


using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

void solve(){
    string s, target; cin >> s >> target;
    string p = target;
    do{
        string n = s;
        string n2 = s;
        int k = 0;
        for (int i = 0; i < (int)n.size(); i++){
            if (n[i] == '?'){
                n[i] = p[k];
                n2[i] = p[k+1];
                k++; 
            }
        }
        if (n.find(target) != string::npos || n2.find(target) != string::npos) {
            cout << "Yes\n";
            return;
        }
    } while(next_permutation(p.begin(), p.end()));
    cout << "No\n";
}

int main(){
    
    //int tc; cin >> tc; while(tc--) solve();
    solve();
}