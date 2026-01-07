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
    ll mov = 0;

    vi A;
    int b;
    while (cin >> b) A.PB(b);

    for (int i = 1; i < n; ++i)
    {
        if (A.at(i) < A.at(i-1)){ 
            mov += (A.at(i-1) - A.at(i));
            A[i] = A[i-1];
        }
    }
    cout << mov;
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
