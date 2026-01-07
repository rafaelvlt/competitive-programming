#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;


int main(){
    int n; cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        m[a] += 1;
    }
    int total = 0;
    total += m[4]; m[4] = 0;
    
    total += m[2]/2;
    if (m[2] % 2 == 0) m[2] = 0;
    else {
        m[2] = 0;
        total++;
        if (m[1] >= 2) m[1] -= 2;
        else if (m[1] == 1) m[1] -= 1;
    }

    int k = min(m[3], m[1]); 
    total += k; m[3] -= k; m[1] -= k;

    if (m[3] > 0) {total += m[3]; m[3] = 0;}

    else if (m[1] > 0) {
        total += (m[1] + 3) / 4; 
        m[1] = 0;
    }
    
    cout << total;
}
