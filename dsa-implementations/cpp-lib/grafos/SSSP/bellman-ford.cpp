/**
 * @brief Algoritmo de Bellman-Ford para SSSP.
 *
 * Encontra o caminho mais curto e detecta ciclos de peso negativo.
 *
 * Complexidade: O(VE)
 *
 * @param s Vértice de origem.
 * @param V Número total de vértices.
 * @param EdgeList Uma lista de todas as arestas no grafo.
 * Formato: vector<tuple<int, int, ll>>
 * Cada tupla é (u, v, w) -> aresta de u para v com peso w.
 * (Nota: Bellman-Ford é mais fácil com Lista de Arestas)
 * @return Um vector<ll> 'dist'.
 * dist[i] = INF se inalcançável.
 * dist[i] = -INF se alcançável por um ciclo negativo.
 * dist[i] = valor do caminho mais curto, caso contrário.
 */
vector<ll> bellmanFord(int s, int V, 
                       const vector<tuple<int, int, ll>>& EdgeList) {
    
    vector<ll> dist(V, INF);
    dist[s] = 0;

    // 1. Fase de Relaxamento Principal
    // Relaxa todas as E arestas, V-1 vezes [cite: 1409]
    for (int i = 0; i < V - 1; i++) {
        for (const auto& edge : EdgeList) {
            int u, v;
            ll w;
            tie(u, v, w) = edge;
            if (dist[u] != INF) { // Só relaxa se u for alcançável
                dist[v] = min(dist[v], dist[u] + w);
            }
        }
    }

    // 2. Fase de Detecção de Ciclo Negativo [cite: 1410]
    // Se for possível relaxar na V-ésima vez (ou mais), encontramos
    // vértices que estão em/são alcançáveis por ciclos negativos.
    for (int i = 0; i < V; i++) { // Repete V vezes para propagar o -INF
        for (const auto& edge : EdgeList) {
            int u, v;
            ll w;
            tie(u, v, w) = edge;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = -INF; // Marca como parte/alcançável de ciclo neg.
            }
        }
    }
    
    return dist;
}
