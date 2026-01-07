#include <bits/stdc++.h>

using namespace std;

int main(){
    int temp;
    int set = 1;
    while(cin >> temp)
    {
        int C, S; C = temp; cin >> S;
        vector<int> m(S+1);
        for (int i = 1; i < S+1; i++) cin >> m[i];
        vector<int> mOrig = m;
        while(m.size() != 2*C+1) m.push_back(0);
        sort(m.begin(), m.end());

        vector<pair<int, int>> chambers(C);
        for (int i = 1; i <= C; i++){
            chambers[i-1] = (make_pair(m[i], m[C*2-i+1]));
        }

        double average = accumulate(m.begin(), m.end(), 0.0)/C;
        double imbalance = 0;
        for (int i = 0; i < C; i++){
            imbalance += abs((chambers[i].first + chambers[i].second) - average);
        }

        cout << "Set #" << set << "\n";
        for (int i = 0; i < C; i++){
            cout << i << ": ";
            if (chambers[i].first != 0) cout << chambers[i].first << " ";
            if (chambers[i].second != 0) cout << chambers[i].second << "\n";
            else cout << "\n"; 
        }
        cout << fixed << setprecision(5);
        cout << "IMBALANCE = " << imbalance << "\n\n";
        set++;
    }
}
