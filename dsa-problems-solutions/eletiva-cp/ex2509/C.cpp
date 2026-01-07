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
    vi data(n);
    forn(i, n) cin >> data[i];
    
    priority_queue<int, vector<int>, greater<int>> A(data.begin(), data.end());
    
    int arr[2];
    while(A.size() > 1){
        arr[0] = A.top(); 
        A.pop();
        arr[1] = A.top();
        A.pop();
        A.push(arr[0] + arr[1] - 1);
    }

    cout << A.top() << '\n';
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	int tt; cin >> tt; while (tt--) solve();
	//solve();
	
	return 0;
}
