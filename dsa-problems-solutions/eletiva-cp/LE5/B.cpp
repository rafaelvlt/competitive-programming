#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int c = 0;
    while(n > 0){
        int md = 0;
        int tmp = n;
        while (tmp > 0){
            md = max(tmp % 10, md);
            tmp /= 10;
        }
        n -= md;
        c++;
    }
    cout << c;
}
