typedef pair<int, int> ii; // In this chapter, we will frequently use these
typedef vector<ii> vii; // three data type shortcuts. They may look cryptic
typedef vector<int> vi; // but they are useful in competitive programming

vi dfs_num; // global variable, initially all values are set to UNVISITED
//vi topsort;   <------- topological sort
void dfs(int u) {

    dfs_num[u] = VISITED; // important: we mark this vertex as visited
    for (int j = 0; j < (int)AdjList[u].size(); j++) { // default DS: AdjList
        ii v = AdjList[u][j]; // v is a (neighbor, weight) pair
        if (dfs_num[v.first] == UNVISITED) // important check to avoid cycle
            dfs(v.first); // recursively visits unvisited neighbors of vertex u
    }
    //topsort.pushback(u); <-------- para guardar em ordem reversa
} // for simple graph traversal, we ignore the weight stored at v.second


/*
main(){
    for (int i = 0; i < V; i++) // this part is the same as finding CCs
        if (dfs_num[i] == UNVISITED)
            dfs2(i);

    // alternative, call: reverse(ts.begin(), ts.end()); first
    for (int i = (int)ts.size() - 1; i >= 0; i--) // read backwards
        cout << ts[i] << '\n';
        
*/