#include <bits/stdc++.h> // Único include necessário
using namespace std;

typedef long long ll;
const ll INF = 1e18; // "Infinito" para capacidade/fluxo

// --- Estrutura de Aresta ---
// Esta struct ainda é necessária para armazenar os detalhes da aresta
struct Edge {
    int to;     // Vértice de destino
    ll cap;     // Capacidade da aresta
    ll flow;    // Fluxo atual na aresta
    int rev;    // Índice da aresta reversa em AdjList[to]
};

// --- Funções Auxiliares ---

/**
 * @brief Adiciona uma aresta (e sua reversa) ao grafo.
 * @param u Vértice de origem.
 * @param v Vértice de destino.
 * @param cap Capacidade da aresta u -> v.
 * @param AdjList A lista de adjacência (passada por referência).
 */
void add_edge(int u, int v, ll cap, vector<vector<Edge>>& AdjList) {
    Edge fwd = {v, cap, 0, (int)AdjList[v].size()};
    Edge bwd = {u, 0,   0, (int)AdjList[u].size()};
    AdjList[u].push_back(fwd);
    AdjList[v].push_back(bwd);
}

/**
 * @brief Executa um BFS para encontrar um caminho de aumento.
 * Preenche os vetores 'p' (predecessor) e 'p_edge' (aresta predecessora).
 * @return true se um caminho de 's' para 't' foi encontrado.
 */
bool bfs_karp(int s, int t, int V, 
              vector<vector<Edge>>& AdjList, 
              vector<int>& p, 
              vector<Edge*>& p_edge) {
    
    fill(p.begin(), p.end(), -1);
    fill(p_edge.begin(), p_edge.end(), nullptr);
    
    p[s] = s;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == t) return true; // Encontrou o sumidouro

        for (auto &e : AdjList[u]) {
            int v = e.to;
            // Se 'v' não foi visitado E a aresta tem capacidade residual
            if (p[v] == -1 && e.cap > e.flow) {
                p[v] = u;         // Define o predecessor
                p_edge[v] = &e;   // Armazena ponteiro para a aresta usada
                q.push(v);
            }
        }
    }
    return false; // Não chegou ao sumidouro
}

// --- Função Principal ---

/**
 * @brief Calcula o Fluxo Máximo de 's' para 't' (Edmonds-Karp).
 * @param s Vértice de origem (source).
 * @param t Vértice de sumidouro (sink).
 * @param V Número total de vértices.
 * @param AdjList A lista de adjacência (será modificada).
 * @return O valor do fluxo máximo.
 */
ll edmondsKarp(int s, int t, int V, vector<vector<Edge>>& AdjList) {
    ll mf = 0; // Max Flow (inicialmente 0)
    
    // Vetores de predecessores, precisam ser alocados aqui
    vector<int> p(V);
    vector<Edge*> p_edge(V);

    // Loop principal: continua enquanto o BFS encontrar um caminho
    while (bfs_karp(s, t, V, AdjList, p, p_edge)) {
        // 1. Encontra o gargalo (flow do caminho)
        ll path_flow = INF;
        for (int v = t; v != s; v = p[v]) {
            path_flow = min(path_flow, p_edge[v]->cap - p_edge[v]->flow);
        }

        // 2. Atualiza o fluxo (augment)
        for (int v = t; v != s; v = p[v]) {
            // Aumenta o fluxo na aresta direta
            p_edge[v]->flow += path_flow;
            
            // Diminui o fluxo na aresta reversa (pela referência 'rev')
            Edge& rev_edge = AdjList[v][p_edge[v]->rev];
            rev_edge.flow -= path_flow;
        }

        mf += path_flow; // Adiciona ao fluxo total
    }
    return mf;
}

// --- Funções Derivadas ---

/**
 * @brief DFS auxiliar para encontrar o lado S do Min-Cut.
 */
void getMinCutDFS(int u, vector<bool>& visited, const vector<vector<Edge>>& AdjList) {
    visited[u] = true;
    for (const auto& e : AdjList[u]) {
        // Se houver capacidade residual e v não foi visitado
        if (e.cap > e.flow && !visited[e.to]) {
            getMinCutDFS(e.to, visited, AdjList);
        }
    }
}

/**
 * @brief Encontra os vértices no lado S (da fonte) do Min-Cut.
 * DEVE ser chamado APÓS a execução de edmondsKarp.
 *
 * @param s O vértice de origem (source).
 * @param V O número total de vértices.
 * @param AdjList A lista de adjacência (APÓS o max flow).
 * @return Um vector<bool> 'visited' onde visited[i] == true
 * significa que o vértice 'i' pertence ao conjunto S.
 */
vector<bool> getMinCut(int s, int V, const vector<vector<Edge>>& AdjList) {
    vector<bool> visited(V, false);
    getMinCutDFS(s, visited, AdjList);
    return visited;
}
