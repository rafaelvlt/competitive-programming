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
    string s;
    cin >> s;
    int max = 1;
    int temp = 1;
    for (int i = 0; i < (int)s.size() ; i++)
    {
        if (i){    
            if (s.at(i) == s.at(i-1)) {
                ++temp;
            }
            else{     
                if (temp > max){
                    max = temp;
                }
                temp = 1;
            }
            
        }
    }
    if (temp > max) max = temp;
    cout << max;
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
	
	return 0;
}
