//Macros
#define F first
#define S second
#define PB push_back
#define MP make_pair

#include <bits/stdc++.h>
//para compilar: 
//g++ -std=c++17 -O2 -Wall nome.cpp -o nome
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

void solve()
{
    int n;
    cin >> n;
    vector<ll> p(n);
    ll f = 0, s = 0;
    for (int i=0; i < n; ++i) {
        cin >> p[i];
        if (p[i] >= f) {
            s = f;
            f = p[i];
        }
        else if (p[i] >= s) s = p[i];
    }

    for (int i=0; i < n; ++i){
        if (p[i] != f) cout << p[i] - f << " ";
        else cout << f - s << " ";
    }
    cout << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
    cin >> t;

	while(t--) solve();
	
	return 0;
}
