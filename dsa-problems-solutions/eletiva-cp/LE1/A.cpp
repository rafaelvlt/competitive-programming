#include<bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, K, Q;
  cin >> N >> K >> Q;
  vector<int> P(N, K-Q);

  int p;
  for (int i = 0; i < Q; i++) {
    cin >> p;
    P[p-1]++;
  }
  
  for (int i = 0; i < N; i++){
    if (P[i] <= 0) cout << "No\n";
    else cout << "Yes\n";
  }
  
}
