/**
 * @brief Algoritmo de Dijkstra para SSSP (Shortest Path from Single Source).
 *
 * Encontra o caminho mais curto de um vértice 's' para todos os outros
 * vértices em um grafo ponderado com arestas de peso NÃO-NEGATIVO.
 *
 * Complexidade: O((E+V) log V)
 *
 * @param s Vértice de origem.
 * @param V Número total de vértices (de 0 a V-1).
 * @param AdjList Lista de adjacência do grafo.
 * Formato: vector<vector<pair<int, ll>>>
 * AdjList[u] = {{v1, w1}, {v2, w2}, ...}
 * Significa arestas u->v1 (peso w1), u->v2 (peso w2), etc.
 * @param p Vetor de predecessores (passado por referência) para
 * reconstrução do caminho. p[v] = u significa que u
 * precede v no caminho mais curto.
 * @return Um vector<ll> 'dist' onde dist[i] é a menor distância de s até i.
 */
vector<ll> dijkstra(int s, int V, 
                    const vector<vector<pair<int, ll>>>& AdjList, 
                    vector<int>& p) {
    
    // 1. Inicialização
    vector<ll> dist(V, INF);
    p.assign(V, -1); // Inicializa vetor de predecessores com -1
    dist[s] = 0;

    // 2. Fila de Prioridade (Min-Heap)
    // Armazena pares (distância, vértice)
    // O 'greater' transforma a max-heap padrão em uma min-heap.
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, s}); // {distância, vértice}

    // 3. Loop principal do algoritmo
    while (!pq.empty()) {
        // Extrai o vértice 'u' com a menor distância 'd'
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // 4. Otimização "Lazy Deletion" (CP3, p. 173)
        // Se 'd' é maior que a distância já registrada, este é um
        // par obsoleto na fila. Pulamos.
        if (d > dist[u]) continue;

        // 5. Relaxamento das Arestas
        // Itera sobre todos os vizinhos 'v' de 'u'
        for (const auto& edge : AdjList[u]) {
            int v = edge.first;
            ll w = edge.second; // Peso da aresta u -> v

            // Se um caminho mais curto para 'v' for encontrado...
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w; // ...atualiza a distância
                p[v] = u;              // ...define 'u' como predecessor de 'v'
                pq.push({dist[v], v}); // ...adiciona o novo par (dist, v) à fila
            }
        }
    }
    return dist;
}

/*
### Derivados (Dijkstra): Imprimindo o Caminho

Após executar Dijkstra, o vetor `p` contém a árvore de caminhos mais curtos. Esta função reconstrói o caminho do `s` até `t`. 
*/

/**
 * @brief Reconstrói o caminho mais curto de s para t.
 * Deve ser chamado APÓS a execução de dijkstra(s, V, AdjList, p).
 *
 * @param t O vértice de destino.
 * @param p O vetor de predecessores preenchido por Dijkstra.
 * @return Um vector<int> contendo o caminho de s para t.
 * Se não houver caminho, retorna um vetor com {-1}.
 */
vector<int> getShortestPath(int t, const vector<int>& p) {
    vector<int> path;
    
    // Se t não for alcançável (predecessor é -1)
    if (p[t] == -1 && t != p[0]) { // p[0] é -1 se 0 for a fonte
        path.push_back(-1);
        return path;
    }

    // Reconstrói o caminho de t de volta para s
    for (int v = t; v != -1; v = p[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end()); // Inverte para s -> t
    return path;
}
