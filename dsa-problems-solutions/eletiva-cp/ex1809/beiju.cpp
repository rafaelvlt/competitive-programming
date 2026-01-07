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

void fbeiju(vector<pi>& pos, vector<string>& beiju, int n, string& t)
{   
    pos.PB(MP(0, 0));
    beiju.PB("");
    auto h = t.find('[', n);
    pos[n].first = (int)h;
    for (int i = pos[n].first+1; i < (int)t.size(); ++i)
    {
        auto f = t.find('[', n+1);
        auto s = t.find_last_of(']', n);
        if (f != string::npos && f != h){
            pos[n+1].first = i;
            fbeiju(pos, beiju, n+1, t);
        }
        else
        {
            pos[n].second = (int)s;
            int st = pos[n].first;
            int end = pos[n].second;
            beiju[n] = (t.substr(st+1, (end-st-1)));
            int len = beiju[n].size();
            if (beiju[n] == "") len = 0;
            if (st > 0 && (t.at(st-1) == '_' && t.at(end+1) == '_'))
                t.replace(st-1, len+3, "");
            else
                t.replace(st, len+2,"");
            break;
        }
    }
}

void solve()
{
    string t;
    while(cin >> t){
        int n = 0;
        vector<string> beiju;
        vector<pi> pos;
        while (t.find('[') != string::npos)
            fbeiju(pos, beiju, n, t);
        int idx = 0;
        for (int i = 0; i < (int)beiju.size(); ++i){
            t.insert(idx, beiju[i]);
            idx += (int)beiju[i].size();
        cout << t << "\n";
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
