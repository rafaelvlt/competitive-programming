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
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    cout << s1[0] << s2[0] << s3[0] << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int T;
    cin >> T;
	while(T--) solve();
	
	return 0;
}
