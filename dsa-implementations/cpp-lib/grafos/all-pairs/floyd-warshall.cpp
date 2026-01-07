/**
 * @brief Algoritmo de Floyd-Warshall para APSP (All-Pairs Shortest Path).
 *
 * Encontra o caminho mais curto entre TODOS os pares de vértices.
 *
 * Complexidade: O(V^3)
 *
 * @param V O número total de vértices.
 * @param AdjMat Matriz de Adjacência (passada por referência).
 * Entrada: AdjMat[i][j] = peso da aresta (i,j), 
 * INF se não houver, 0 se i == j.
 * Saída: AdjMat[i][j] = caminho mais curto de i para j.
 * @param p Matriz de predecessores (passada por referência)
 * para reconstrução do caminho.
 */
void floydWarshall(int V, vector<vector<ll>>& AdjMat, vector<vector<int>>& p) {
    // 1. Inicialização de 'p'
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            p[i][j] = i; // O predecessor de j no caminho i->j é i [cite: 158]
        }
    }

    // 2. Algoritmo principal
    // A ordem dos loops (k -> i -> j) é crucial! 
    for (int k = 0; k < V; k++) { // k = vértice intermediário
        for (int i = 0; i < V; i++) { // i = origem
            for (int j = 0; j < V; j++) { // j = destino
                
                // Previne overflow de INF + INF
                if (AdjMat[i][k] == INF || AdjMat[k][j] == INF) continue;

                if (AdjMat[i][k] + AdjMat[k][j] < AdjMat[i][j]) {
                    AdjMat[i][j] = AdjMat[i][k] + AdjMat[k][j];
                    p[i][j] = p[k][j]; // [cite: 158]
                }
            }
        }
    }
}

// 1. Resolvendo SSSP com APSP:
// Após executar floydWarshall(V, AdjMat, p), a linha 's' da
// matriz, AdjMat[s], contém todas as distâncias mais curtas
// a partir de 's'. É O(V^3), mais lento que Dijkstra (O(E log V)),
// mas útil se o grafo for pequeno (V <= 400). [cite: 155]

// 2. Reconstrução de Caminho (APSP):
// (Use a mesma função getShortestPath(t, p[s]) da seção Dijkstra,
// mas passe p[s] (a linha 's' da matriz de predecessores) como
// o vetor de predecessores.)
// OU, uma versão específica do Floyd:
vector<int> getPathAPSP(int s, int t, const vector<vector<int>>& p) {
    vector<int> path;
    if (p[s][t] == -1) return path; // Assumindo -1 se não houver caminho
    path.push_back(s);
    int curr = s;
    while (curr != t) {
        curr = p[curr][t]; // ERRO NA LÓGICA DO CP3. A lógica correta é:
        // p[i][j] = k se k for o último vértice ANTES de j no caminho i->j
        // A lógica do livro p[i][j] = p[k][j] é para reconstrução recursiva.
        
        // Vamos seguir a lógica do livro[cite: 158]:
        // void printPath(int i, int j) {
        //   if (i != j) printPath(i, p[i][j]);
        //   printf(" %d", j);
        // }
        // Aqui está a versão iterativa disso:
        curr = t;
        while (curr != s) {
            path.push_back(curr);
            curr = p[s][curr];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
    }
    return path;
}


// 3. Detectando Ciclos Negativos:
// Após executar floydWarshall, verifique a diagonal principal. [cite: 159]
// Se AdjMat[i][i] < 0 para qualquer 'i', então o vértice 'i'
// faz parte ou é alcançável a partir de um ciclo de peso negativo.
bool hasNegativeCycle(int V, const vector<vector<ll>>& AdjMat) {
    for (int i = 0; i < V; i++) {
        if (AdjMat[i][i] < 0) {
            return true;
        }
    }
    return false;
}

// 4. Encontrando o Ciclo Mais Barato (Girth):
// Se todos os AdjMat[i][i] permanecerem 0 (ou INF se você inicializou
// assim [cite: 159]), o ciclo positivo mais barato é min(AdjMat[i][j] + AdjMat[j][i])
// para todo i != j. Se você inicializar AdjMat[i][i] = INF,
// o min(AdjMat[i][i]) após a execução é o ciclo mais barato.
