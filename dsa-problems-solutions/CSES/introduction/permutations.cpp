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

    if (n == 2 || n == 3) {
        cout << "NO SOLUTION\n";
    }
    else if (n==1) cout << "1\n";
    else{
        for (int i = 2 ; i <= n; i+=2)
        {
            cout << i << " ";
        }
        for (int i = 1; i<= n; i+=2){
            cout << i << " ";
        }

    }



}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	solve();
	
	return 0;
}
