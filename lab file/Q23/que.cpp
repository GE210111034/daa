#include <bits/stdc++.h>
using namespace std;
typedef vector<int> Vertex;
typedef vector<Vertex> Graph;
typedef vector<pair<int, pair<int, int>>> Edge;
typedef vector<int> Subset;
void InputGraphMatrix(Graph&);
int Find(Subset, int);
Edge Union(Graph);
Graph Kruskal(Graph);
int CalcMinSpanningWeight(Graph);
int main(void) {
    int size; cout << "Enter Vertex No: "; cin >> size;
    Graph G(size, Vertex(size, 0));
    cout << "Ener Matrix :" << endl;
    for(auto& vtx : G) for(auto& edge : vtx) cin >> edge;
    cout << "Original Graph :" << endl; ShowGraph(G);
    Graph MST = Kruskal(G);
    cout << "Min Spanning Weight: " << CalcMinSpanningWeight(MST) << endl;
    return 0;
}
int Find(Subset s, int i){
    if(s[i] == -1) return i;
    return Find(s, s[i]);
 }
Edge Union(Graph G){
    Edge edges; int size = G.size();
        for (int i = 0; i < size; i++) 
            for (int j = 0; j < i; j++) 
            if(G[i][j] != 0) edges.push_back({G[i][j], {j, i}});
        sort(edges.begin(), edges.end());
    return edges;
 }
Graph Kruskal(Graph G){
    int size = G.size(); Graph result(size, Vertex(size, -1));
    Subset subset(size, -1); Edge edges = Union(G); int count = 0;
    for (auto edge : edges) {
        int weight = edge.first, u = edge.second.first, v = edge.second.second;
        int setU = Find(subset, u); int setV = Find(subset, v);
        if (setU != setV) result[u][v] = result[v][u] = weight, subset[u] = v, count++;
        if (count == size - 1) break;
    } return result;
 }
 int CalcMinSpanningWeight(Graph G){
    int size = G.size(), w = 0;
    for (int i = 0; i < size; i++) for (int j = 0; j < i; j++) if(G[i][j]) w += G[i][j];
    return w;
}
