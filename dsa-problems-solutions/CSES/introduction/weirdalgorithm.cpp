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
    ll n;
    cin >> n;
    cout << n;
    while (n > 1){
        if (!(n%2)) n /= 2;
        else n = n * 3 + 1;
        cout << " " << n;
    }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif


	solve();
	
	return 0;
}
