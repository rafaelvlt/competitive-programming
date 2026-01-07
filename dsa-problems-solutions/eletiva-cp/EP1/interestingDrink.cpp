//Macros
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define forn(i, n) for(int i=0; i < int(n); ++i)
#include <bits/stdc++.h>
//para compilar: 
//g++ -std=c++17 -O2 -Wall nome.cpp -o nome
//SE FOR DEBUGAR TIRAR O O2
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

void solve()
{
    int n; cin >> n;
    vi p(n);
    forn(i,n) cin >> p[i];
    sort(p.begin(), p.end());

    int q; cin >> q;

    for (int i = 0; i < q; ++i){
        int m; cin >> m;
        auto idx = upper_bound(p.begin(), p.end(), m);
        cout << idx - p.begin() << "\n";
    }


}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);



	//int tt; cin >> tt; while (tt--) solve();
	solve();
	
	return 0;
}
