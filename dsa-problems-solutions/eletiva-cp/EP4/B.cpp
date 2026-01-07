#include <bits/stdc++.h>

using namespace std;

int board[8][8];
int row[8];
int sol = 0;
void backtrack(int c){
    //se conseguiu ir até todas colunas(7), a solução é válida
    if (c == 8){
        sol++;
        return;
    }
    else{
        //para cada linha
        for (int r = 0; r < 8; r++){
            //checa se não é proibido colocar a rainha antes de tudo
            if (board[r][c] == 1) continue;
            
            //checa se colocar a rainha na coluna c linha r não daria conflito com rainhas previamente colocadas
            bool can = true;
            for (int p = 0; p < c; p++){
                //caso compartilhe mesma linha, ou esteja na diagonal, não é valida
                if (row[p] == r || (abs(row[p] - r) == abs(p - c))) {
                    can = false;
                    break;
                }
            }
            // se for valida, o caminho ainda é possível, coloca a rainha na coluna c linha r e recursa para próxima coluna
            if (can){
                row[c] = r;
                backtrack(c+1);
            }
        }
    }
}

void solve(){
    //board de possibilidades se pode ou n colocar
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            char a; cin >> a;
            if (a == '.') board[i][j] = 0;
            else board[i][j] = 1;
        }
    }
    backtrack(0);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();
    cout << sol;
    //int tt; cin >> tt; while(tt--) solve();
    
}
