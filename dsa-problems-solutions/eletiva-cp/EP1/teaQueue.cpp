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
    vector<pi> st(n);
    forn(i,n){
        int l, r; cin >> l >> r;
        st[i] = MP(l, r);
    }
    int lst = 0;
    vi ans(n);
    forn(i,n){
        int pt = max(lst+1, st[i].first);
        if (pt <= st[i].second){
            ans[i] = pt;
            lst = pt;
        }
        else{
            ans[i] = 0;
        }
    }
    forn(i,n) cout << ans[i] << " ";
    cout << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int tt; cin >> tt; while (tt--) solve();
	//solve();
	
	return 0;
}
