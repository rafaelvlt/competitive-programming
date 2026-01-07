#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using ll = long long;

const ll INF = 1e18;
int maxN = 400005;
const int maxValP = 6000000;

vector<int> primos;
vector<ll> psum;
bitset<maxValP> bs;

void sieve(ll upperbound){
  bs.set();
  bs[0] = bs[1] = 0;
  for (ll i=2;i <= upperbound; i++){
    if (bs[i]) {
      for(ll j = i*i;j<= upperbound; j+=i) bs[j] = 0;
      primos.push_back((int)i);
      if (primos.size() >= maxN) break;
    }
  }
}

void preC(){
  sieve(maxValP);
  psum.push_back(0);
  for (int p : primos){
    psum.push_back(psum.back() + p);
  }
}
void solve(){
  int n; cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  sort(a.rbegin(), a.rend());
  ll tempsum = 0;
  int max = 0;

  for (int i = 1; i <= n; i++){
    tempsum += a[i-1];
    if (tempsum >= psum[i]){
      max = i;
    }
    else break;
  }

  cout << n - max << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    preC();
    int tt; cin >> tt; while(tt--) solve();
    //solve();
}
