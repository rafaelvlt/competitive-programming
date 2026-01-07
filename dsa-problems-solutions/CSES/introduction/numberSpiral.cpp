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
    ll x, y;
    cin >> y >> x;
    ll z = max(y, x);
    if ((z == y)){
        if (y % 2 == 0) {
            cout << y*y+1 - x << "\n";
        }
        else cout << (y-1)*(y-1) + x << '\n';
    }
    
    else if ((z == x)){
        if (x % 2 != 0) {
           cout << x*x+1 - y << '\n';
        }
        else cout << (x-1)*(x-1) + y << '\n';
    }
}


   // 1  2  9  10  25 26 49
   // 4  3  8  11  24 27 48
   // 5  6  7  12  23 28 47
   // 16 15 14 13  22 29 46
   // 17 18 19 20  21 30 45
   // 36 35 34 33  32 31 44
   // 37 38 39 40  41 42 43
   // se y % 2 == 0 ; y^2      ; rows decrement
   // se y % 2 == 1 ; (y-1)²+1 ; rows increment
   // same thing for x


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
	
	return 0;
}
