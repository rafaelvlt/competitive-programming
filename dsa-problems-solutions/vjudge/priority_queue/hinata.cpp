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
	vector<ll> A(n);
	forn(i,n) cin >> A[i];
	ll idx = 0;
	priority_queue<ll> S;
	ll product = 1;
	ll least = 0;
	vector<ll> aux = {A[0], A[1], A[2]};
	sort(aux.rbegin(), aux.rend());
	while (idx < n){
		S.push(A[idx]);
		if (idx < 2) {
			cout << -1 << '\n';
			product *= S.top();
		}
		else {
			cout << product << '\n';
			
		}
		idx++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//#ifndef ONLINE_JUDGE
    //  freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
    //#endif


	//int tt; cin >> tt; while (tt--) solve();
	solve();
	
	return 0;
}
