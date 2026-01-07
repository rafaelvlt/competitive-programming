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
    map<ll, ll> m;
    int n; cin >> n;
    forn(i, n){
        int b;
        ll k, v;
        cin >> b;
        if (b){
            cin >> k;
            if (m[k] != 0) cout << m[k] << '\n';
            else{
                m[k] = 0;
                cout << m[k] << '\n';
            }
        }
        else{
            cin >> k >> v;
            m[k] = v;
        }
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
