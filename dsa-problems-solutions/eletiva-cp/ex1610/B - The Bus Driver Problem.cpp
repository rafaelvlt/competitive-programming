#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, d, r; cin >> n >> d >> r; 
    while(n != 0 && d != 0 && r != 0){
        vector<int> m(n);
        for (int i = 0; i < n; i++) cin >> m[i];
        vector<int> e(n);
        for (int i = 0; i < n; i++) cin >> e[i];
        vector<int> drivers(n, d);

        sort(drivers.begin(), drivers.end());
        sort(m.begin(), m.end());
        for (int i = 0; i < n; i++){
            drivers[i] -= m[i];
        }
        sort(drivers.begin(), drivers.end());
        sort(e.begin(), e.end());            
        for (int i = 0; i < n; i++){
            drivers[i] -= e[i];
        }
        int pay = 0;
        for (int i =0; i<n; i++){
            if (drivers[i] < 0) pay += (r*abs(drivers[i]));
        }
        cout << pay << '\n';
        cin >> n >> d >> r; 
    }

}
