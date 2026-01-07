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

int main()
{
	ios::sync_with_stdio(false); //não usar scanf ou printf pois tá dessincronizado
	cin.tie(nullptr);
	
	int T;
  int l; //comprimento
  int m; // qtd
  cin >> T;

  while (T--)
    {
      cin >> l;
      cin >> m;

      queue<pair<int, string>> LQ;
      queue<pair<int, string>> RQ;
      string side = "left";

      l *= 100;
      int curr = l;
      int viag = 0;
      for (int i = 0; i < m; i++)
      {
        pair<int, string> B;
        int f;
        string s;

        cin >> f >> s;

        B.F = f;
        B.S = s;

        if (B.S == "left") LQ.push(B);
        else RQ.push(B);
	    }
     
      while (!(LQ.empty() && RQ.empty()))
      {
        if (side == "left")
        {
            while (!LQ.empty() && (curr - LQ.front().first >= 0))
            {
              curr -= LQ.front().first;
              LQ.pop();
            }
        }
        else {
            while (!RQ.empty() && (curr - RQ.front().first >= 0))
            {
              curr -= RQ.front().first;
              RQ.pop();
            }
          }

        viag++;
        side = (side == "left") ? "right" : "left";
        curr = l;

      }
      cout << viag << endl;
    }

    return 0;
}
