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
    int n;
    cin >> n;
    vector<pi> teapot;
    vector<pi> students(n);
    vector<string> pr(n);
    int l, r;
    pi z = MP(0, 0);
    forn(i,n){
        cin >> l >> r;
        students[i] = MP(l, r);
    }
    // para cada i no intervalo de 2 até n, o i <= o do anterior
    int sec = 1;
    int idx = 0;
    while(idx < n)
    {
        for (int i = idx; i < (int)students.size(); ++i){
            if (students[i].first == sec){
                teapot.push_back(students[i]);
            }
        }
        pr[idx] = to_string(sec) + ' ';
        ++idx;
        //second
        for (int i = idx; i < (int)teapot.size(); ++i){
            if (sec >= teapot[i].second) teapot[i] = z;
        }
        for (int i = idx; i < (int)teapot.size(); ++i){
            if(teapot[i] == z) {
                pr[i] = "0 ";
                ++idx;
            }
        }
        ++sec;
    }
    for (int i = 0; i < (int)pr.size(); ++i) cout << pr[i];
    cout << "\n";
}




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	int tt; cin >> tt; while (tt--) solve();
	//solve();
	
	return 0;
}
