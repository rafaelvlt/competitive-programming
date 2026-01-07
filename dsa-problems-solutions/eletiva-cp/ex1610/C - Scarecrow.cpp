#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n; cin >> n;
    if (n == 0) {cout << 0 << '\n';}
    vector<char> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
    if (n == 1){
        if (grid[0] == '.') cout << 1 << '\n';
        else cout << 0 << '\n';
        return;
    }

    vector<bool> placed(n);
    int count = 0;
    for (int f = 0; f< n; f++){
        if (grid[f] == '.' && placed[f] == 0) {
            if (f <= n-1) placed[f] = 1;
            if (f <= n-2) placed[f+1] = 1;
            if (f <= n-3) placed[f+2] = 1;
            count++;
        }
    }
    cout << count << '\n';

}
int main(){
    int tt; cin >> tt; for (int i = 1; i <= tt; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
}
