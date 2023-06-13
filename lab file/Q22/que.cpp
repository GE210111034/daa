#include <bits/stdc++.h>
using namespace std;
typedef vector<int> Vertex;
typedef vector<Vertex> Graph;
typedef vector<pair<int, int>> Edge;
typedef vector<bool> Visited;
int FindMinEdgeDist(Vertex, Visited&);
Graph Prims(Graph);
int CalcMinSpanningWeight(Graph);
int main() {
    cout << "Enter Vertex No: ";
    int size; cin >> size;
    Graph G(size, Vertex(size, 0)); cout << "Enter Matrix:" << endl;
    for (auto& vtx : G) for (auto& edge : vtx) cin >> edge;
    Graph MST = Prims(G);
    cout << "Min Spanning Weight: " << CalcMinSpanningWeight(MST) << endl;
    return 0;
}
int FindMinEdgeDist(Vertex vtx, Visited& Flag) {
    int min = INT_MAX; int v = -1, size = vtx.size();
    for (int j = 0; j < size; j++) {
        if (!Flag[j] && vtx[j]) {  // not in selected and there is an edge
            if (min > vtx[j]) min = vtx[j], v = j;
        }
    } return v;
}
Graph Prims(Graph G) {
    int size = G.size(); Visited Flag(size, false); Graph result(size, Vertex(size, 0));
    int u, v; int count = 0; Flag[0] = true; // Start with the first vertex
    while (count < size - 1) {
        for (int i = 0; i < size; i++) {
            if (Flag[i]) { v = FindMinEdgeDist(G[i], Flag); if(v != -1) u=i;}
        }
        if(u != -1 && v != -1) result[u][v] = result[v][u] = G[u][v], Flag[v] = true;
        count++;
    } return result;
}
int CalcMinSpanningWeight(Graph G){
    int size = G.size(), w = 0;
    for (int i = 0; i < size; i++) for (int j = 0; j < i; j++) if(G[i][j]) w += G[i][j];
    return w;
}