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
    int number; cin >> number;
    int divisors = 0;
    for (int i = 1; i*i <= number; ++i){
        if (!(number%i)){
            if (number/i != i) divisors += 2;
            else divisors++;
        }
    }
    cout << divisors << '\n';
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
