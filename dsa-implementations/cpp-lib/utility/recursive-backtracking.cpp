#include <bits/stdc++.h>

using namespace std;

void backtrack(vector<int>& current_solution /*, ...outros_parametros_de_estado... */) {
    
    // Caso base
    if (1 /* CONDIÇÃO DE SUCESSO ALCANÇADA */) {
        // processa a solução
        // Exemplo:
        // for(int val : current_solution) printf("%d ", val);
        return; // Retorna para continuar a busca por outras soluções, se houver.
    }

    // Outro caso base/pruning
    if (1 /* Condição */) {
        return; // Abandona este caminho da busca (backtrack).
    }


    // Passo recursivo
    for (;;/* CADA ESCOLHA POSSÍVEL `choice` */) {
        
        // Pruning verifica se a escolha é promissora
        if (1 /* A ESCOLHA `choice` É VÁLIDA PARA O ESTADO ATUAL */) {
            
            // a) FAÇA A ESCOLHA
            // Adicione a escolha à solução parcial e atualize o estado.
            // Exemplo:
            // current_solution.push_back(choice);
            // used[choice_index] = true;

            // b) RECURSE
            // Chame a função para o próximo passo da construção.
            backtrack(current_solution /*, ...estado_atualizado... */);

            // c) DESFAÇA A ESCOLHA (BACKTRACK)
            // Remova a escolha da solução parcial e reverta o estado.
            // Isso é crucial para que outras escolhas possam ser exploradas.
            // Exemplo:
            // current_solution.pop_back();
            // used[choice_index] = false;
        }
    }
}
