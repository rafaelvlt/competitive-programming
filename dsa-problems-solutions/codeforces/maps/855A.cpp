#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    map<string, int> m;
    for(int i = 0; i < n; ++i){
        string s; cin >> s;
        if (m[s] == 0){
            m[s] = 1;
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
}
