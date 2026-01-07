#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vll = vector<long long>;
using pii = pair<int, int>;
using ll = long long;

const ll INF = 1e18;

void solve()
{

    int n;
    cin >> n;
    vector<vi> AdjMat(n, vi(n, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int w;
            cin >> w;
            AdjMat[i][j] = w;
            AdjMat[j][i] = w;
        }
    }

    vector<vector<int>> custos = AdjMat;

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (AdjMat[i][k] == -1 || AdjMat[k][j] == -1)
                    continue;

                if (AdjMat[i][k] + AdjMat[k][j] < AdjMat[i][j])
                {
                    AdjMat[i][j] = AdjMat[i][k] + AdjMat[k][j];
                }
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < n && ans != -1; i++)
    {
        for (int j = 0; j < n && ans != -1; j++)
        {
            if (AdjMat[i][j] < custos[i][j])
            {
                ans = -1;
            }
        }
    }
    if (ans != -1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (k == i || k == j)
                        continue;
                    if (custos[i][j] == custos[i][k] + custos[k][j])
                    {
                        ans++;
                        break;
                    }
                }
            }
        }
    }

    if (ans == -1)
        cout << -1 << '\n';
    else
        cout << ans / 2 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // int tt; cin >> tt; while(tt--) solve();
    solve();
}
