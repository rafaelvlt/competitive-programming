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
    int n; 
    cin >> n;
    map<int, int> nd;
    int s = 2'000'000'000;
    int m = 0;
    forn(i,n){
        int buff; cin >> buff;
        nd[buff] += 1;
        s = min(buff, s);
        m = max(buff, m);
    }
    vector<unordered_set<int>> sets;
    int idx = 0;
    int lst;
    while(!nd.empty()){
        sets.PB({});
        for (int i = s; i < m; ++i) {
            if (nd[i] == 0) nd.erase(i);
            else if ((nd[i] > 0 && nd[i+1] > 0) && (lst == nd[i] - 1)) {
                sets[idx].emplace(i); 
                nd[i] -= 1;    
            } 
        } 
        ++idx;
    }
    cout << idx+1 << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	int tt; cin >> tt; while (tt--) solve();
	//solve();
	
	return 0;
}
