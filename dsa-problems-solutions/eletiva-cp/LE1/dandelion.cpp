//Macros
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)


#include <bits/stdc++.h>
//para compilar: g++ -std=c++17 -O2 -Wall test.cpp -o test
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

void solve(){
    int n;
    cin >> n;
    vector<ll> dfe;
    vector<ll> dfo;
    ll sum = 0;
    
    for (int i = 0; i < n; i++ ){
        ll buff;
        cin >> buff;

        if (buff % 2) dfo.push_back((ll)buff);
        else dfe.push_back((ll)buff);           
    }
    if (!(dfo.empty())){
        sort(dfo.rbegin(), dfo.rend());
        sum += dfo.front();
        dfo.erase(dfo.begin());
        if (!(dfe.empty())){
            for (ll valor : dfe) sum += valor;            
        }
        for (int i = 0; i < ((int)dfo.size())/2; i++){
            sum += dfo[i];
        }          
    }

    cout << sum << "\n";
}


int main()
{
	ios::sync_with_stdio(false); //não usar scanf ou printf pois tá dessincronizado
	cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) solve();
	return 0;
}
