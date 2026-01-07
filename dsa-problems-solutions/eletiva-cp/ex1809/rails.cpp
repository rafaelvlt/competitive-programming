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
    while (cin >> n && n != 0){
        stack<int> st;

        int buff;
        while (cin >> buff && buff != 0){

            vi tb(n);
            tb[0] = buff;
            for (int i = 1; i < n; ++i){
                cin >> tb[i];   
            }

            int ta = 1;
            int idx = 0;
            while (idx < n){
                if(!(st.empty()) && st.top() == tb[idx]){
                    st.pop();
                    ++idx;    
                }
                else if(ta <= n){
                    st.push(ta);
                    ta++;
                }
                else{
                    break;
                }
            }
        if (idx == n) cout << "Yes\n";
        else cout << "No\n";  
        }
        cout << "\n";
    }
}   
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve();
	
	return 0;
}
