#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
    int l;
    int contagem = 0;
    while (cin >> l){
        int n; cin >> n;
        vector<int> cd(n);
        for (int i = 0; i < n; i++){
            cin >> cd[i];
        }
        int idx = 0;
        int maxSum = 0;
        int maxTrackcount = 0;
        int power_set_size = 1 << n; 
        for (int i = 0; i < power_set_size; i++) {
            int sum = 0;
            int trackCount = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    sum += cd[j];
                    trackCount++;
                }
            }
            if (sum <= l){
                if (sum > maxSum){
                    idx = i;
                    maxSum = sum;
                    maxTrackcount = trackCount;
                }
                else if (sum == maxSum && trackCount > maxTrackcount){
                    idx = i;
                    maxTrackcount = trackCount;
                }
            }
        }
        for (int i = 0; i < n; i++){
            if (idx & (1 << i)){
                cout << cd[i] << " ";
            }
        }
        cout << "sum:" << maxSum << '\n';
    }

}



int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();
    //int tt; cin >> tt; while(tt--) solve();
    
}
