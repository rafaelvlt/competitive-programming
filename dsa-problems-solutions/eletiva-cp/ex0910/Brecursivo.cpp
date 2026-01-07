#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> subset;
vector<int> b;
int l;
bool found = false;

void search(int k){
    
    if (found) return;

    if (k == n){
        int sum = 0;
        for (int idx: subset){
            sum += b[idx];
        }
        if (sum == l) found = true;
    }
    else{
        search(k+1);
        subset.push_back(k);

        search(k+1);
        subset.pop_back();
    }
}

void solve(){
    cin >> l >> n;
    b.resize(n);
    b.clear();
    for (int i = 0; i < n; i++) cin >> b[i];
    search(0);

    if (found) cout << "YES\n";
    else cout << "NO\n";
    found = false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int tt; cin >> tt; while(tt--) solve();
}
