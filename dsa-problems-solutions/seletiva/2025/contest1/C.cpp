#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    string s; cin >> s;
    int idx = 0;
    int count = 0;
    bool cursor = false;
    while (idx < s.size()){
        if (s[idx] == '|' && idx != 0) {
            cout << count << " ";
            count = 0;
            idx++;
        }
        else if (s[idx] == '-'){
            count++; 
            idx++;}
        else{
            idx++;
        }
    }    
}
