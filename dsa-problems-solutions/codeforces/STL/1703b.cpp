//Macros
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define forn(i, n) for (int i = 0; i < int(n); ++i)


#include <bits/stdc++.h>
//para compilar: 
//g++ -std=c++17 -O2 -Wall nome.cpp -o nome
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;


/* 
outro jeito de resolver
vector de booleanos denotando se o time resolveu o problema i ainda
ter uma string sum
também
bool visto[26] -> 26 letras totaisl
for (char c: string){
	if (!visto[c - 'A']){res += 2 ; visto[c - 'A'] = true;}
	else ++res;
}

*/


void solve()
{
	int l;
	cin >> l;
    string pb;
	cin >> pb;
	string seen;
	int bl = 0;
	for (char c : pb){
		if (seen.find(c) != string::npos) ++bl;
		else{
			bl += 2;
			seen += c;
		}
	}
	cout << bl << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int tt; cin >> tt; while (tt--) solve();
	//solve();
	return 0;
}
