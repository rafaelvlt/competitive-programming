#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
   int n; cin >> n;
   vector<string> sarr(n);
   for (string& s : sarr) cin >> s;
   
   char arr[n][n];

   for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            arr[i][j] = sarr[i][j]; 
        }
   }

   int cnt = 0;
   vector<vector<pair<int, int>>> inc;
   pair<int, int> i1;
   pair<int, int> i2;
   pair<int, int> i3; 
   for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            bool candidate = false;
            bool found = false;
            if (arr[i][j] == 'o'){
                i1 = make_pair(i, j);
                for (int z = 0; z < n && !candidate; z++){
                    if (arr[i][z] == 'o' && z != j){
                        candidate = true;
                        i2 = make_pair(i, z);

                    }
                for (int y = 0; y < n && candidate && !found; y++){
                    if (arr[y][j] == 'o' && y != i && y != i2.first){
                        found = true;
                        i3 = make_pair(y, j);
                        }
                    else if (arr[y][i2.second] == 'o' && y != i && y != i2.first){
                        found = true;
                        i3 = make_pair(y, i2.second);
                        }
                    for (int k = 0; k < inc.size() && found; k++){
                        if ((vector<pair<int, int>>){i1, i2, i3} == inc[i]) found = false;
                    }
                    if (found) inc.push_back({i1, i2, i3});
                }

                }
            }
        }
   }
   for (auto a : inc){
        for (auto b: a){
            cout << '(' << b.first << " " << b.second << ')' << " ";
        }
        cout << '\n';
   }
   cout << inc.size();


}
