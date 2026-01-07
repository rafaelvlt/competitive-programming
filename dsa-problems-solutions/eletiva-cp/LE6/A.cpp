#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using ll = long long;

vector<string> grid;
vector<vector<bool>> visited;
string snuke = "snuke";

int H, W;
int dr[] = {1,0, 0, -1}; 
int dc[] = {0,1,-1, 0};

bool ans = false;

void floodfill(int r, int c, int nextidx) {
    if (r < 0 || r >= H || c < 0 || c >= W) return;
    if (grid[r][c] != snuke[nextidx]) return;
    if (visited[r][c]) return;
    visited[r][c] = true;
    for (int d = 0; d < 4; d++) floodfill(r + dr[d], c + dc[d], (nextidx+1) % 5);
    if (r == H-1 && c == W-1){
        ans = true;
        return;
    }
}



int main(){
    cin >> H >> W;
    grid.resize(H);
    visited.resize(H, vector<bool>(W));
    for (int i = 0; i < H; i++) cin >> grid[i];
    floodfill(0, 0, 0);
    if (ans) cout << "Yes\n";
    else cout << "No\n";
}