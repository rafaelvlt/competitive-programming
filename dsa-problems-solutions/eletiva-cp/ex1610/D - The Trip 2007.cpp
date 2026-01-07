#include <bits/stdc++.h>

using namespace std;

int main(){
    int tt; 
    cin >> tt;
    while(tt != 0){
        map<int, int> A;
        for (int i = 0; i<tt; i++) {
            int a; cin >> a;
            A[a] += 1;
        }
        if (tt == 1) cout << 1 << '\n' << A.begin()->second << "\n"; 
        else{
            vector<pair<int, int>> ppa;
            for (auto it = A.begin(); it != A.end(); it++){
                auto next = it;
                int m = 0;
                if (it != --A.end()){
                    next++;
                    m = min(next->second, it->second);
                    it->second -= m;
                }
                for (int i = 0; i < m; i++){
                    ppa.push_back(make_pair(it->first, next->first));
                }
            }
            int visible = 0;
            for (auto it = A.begin(); it != A.end(); it++){
                visible += it->second;
            }
            cout << visible << '\n';
            for (int i = 0; i < ppa.size(); i++){
                cout << ppa[i].first << " " << ppa[i].second << "\n";
            }
        }
        cin >> tt;
    }
    
}
