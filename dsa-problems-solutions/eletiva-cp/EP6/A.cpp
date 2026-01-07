#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using ll = long long;

vector<string> grid;
int n, m;
int dr[] = {1,0, 0, -1}; 
int dc[] = {0,1,-1, 0};

void floodfill(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= m) return;
    if (grid[r][c] != '.') return; 
    grid[r][c] = 'f';
    for (int d = 0; d < 4; d++)
        floodfill(r + dr[d], c + dc[d]);
}


int main(){
    cin >> n >> m;

    grid.resize(n);

    for (int i = 0; i < n; i++){
        cin >> grid[i];
    }
    bool end = false;
    int ans = 0;
    while (!end){
        end = true;
        for (int i = 0; i < n; i++){
            int j = grid[i].find('.'); 
            if (j != string::npos){
                floodfill(i, j);
                ans++;
                end = false;
            }
        }
    }
    cout << ans << '\n';
}