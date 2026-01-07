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
    ll sum = 0;
    for (int i = 1 ; i < n; ++i) {
        int a;
        cin >> a; 
        sum += a;
    }
    cout << (((n*(n+1))/2) - sum);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
	
	return 0;
}
