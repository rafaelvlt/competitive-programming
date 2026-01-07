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
    priority_queue<ll, vector<ll>, greater<ll>> hPQ;
    forn(i, n) {
        int b; cin >> b;
        A[i] = b;
        if (!b) hPQ.push(i); 
    }
    ll power = 0;
    int lst = 0;
    priority_queue<ll> pPQ;
    
    while(!hPQ.empty()){
        for (int i = lst; i < hPQ.top(); ++i){
            pPQ.push(A[i]);
        }
        lst = hPQ.top();
        if (!pPQ.empty()){
            power += pPQ.top();
            hPQ.pop(); pPQ.pop();
        }
        else hPQ.pop();
    }
    cout << power << "\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//#ifndef ONLINE_JUDGE
    //  freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
    //#endif


	int tt; cin >> tt; while (tt--) solve();
	//solve();
	
	return 0;
}
