#include <bits/stdc++.h>

using namespace std;

int main(){
    
    map<int, int> m;
    vector<int> s;
    int a;
    bool seen = false;
    while(cin >> a){
        m[a] += 1;
        for (int i : s){
            if (i == a) seen = true;
        }
        if (!seen) s.push_back(a);
        seen = false;
    }
    
    for (int i : s){
        cout << i << " " << m[i] << '\n';
    }
}
