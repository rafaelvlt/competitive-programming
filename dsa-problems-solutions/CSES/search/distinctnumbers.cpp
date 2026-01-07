#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int n; cin >> n;
    set<ll> s;
    for (int i = 0; i < n; i++){
        ll b; cin >> b;
        s.insert(b);
    }
    cout << s.size();
}
