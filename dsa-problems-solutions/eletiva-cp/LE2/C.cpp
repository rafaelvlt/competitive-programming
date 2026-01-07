#include <bits/stdc++.h>

using namespace std;

void solve(){
    int b, sg, sb; cin >> b >> sg >> sb;
    priority_queue<int> B;
    priority_queue<int> G;
    for (int i = 0; i < sg; ++i){
        int p; cin >> p;
        G.push(p);
    }
    for (int i = 0; i < sb; ++i){
        int q; cin >> q;
        B.push(q);
    }

    while (1){
        vector<int> bg, bb;
        int bs = B.size(), gs = G.size();
        for (int i = 0; i < b && (i < bs && i < gs); ++i){
            int blue, green;
            blue = B.top(); B.pop();
            bb.push_back(blue);
            green = G.top(); G.pop();
            bg.push_back(green);
        }
        for (int i = 0; i < bb.size(); ++i){
            if (bb[i] > bg[i]) B.push(bb[i]-bg[i]);
            else if(bg[i] > bb[i]) G.push(bg[i] - bb[i]);
        }

        if (B.size() == 0 && G.size() == 0){
            cout << "green and blue died\n";
            break;
        }
        else if (B.size() == 0){
            cout << "green wins\n";
            gs = G.size();
            for (int i = 0; i < gs; ++i){
                cout << G.top() << '\n';
                G.pop();
            }
            break;
        }   
        else if (G.size() == 0){
            cout << "blue wins\n";
            bs = B.size();
            for (int i = 0; i < bs; ++i){
                cout << B.top() << '\n';
                B.pop();
            }
            break;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt; while(tt--){
        solve();
        if (tt != 0) cout << "\n";
    }
}
