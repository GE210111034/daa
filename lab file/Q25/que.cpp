#include <bits/stdc++.h>
using namespace std;

typedef vector<int> Vertex;
typedef vector<Vertex> Graph;
typedef vector<pair<int, int>> Edge;
typedef vector<bool> Visited;

void ShowGraph(Graph);
void InputGraphMatrix(Graph&);
int FindMaxEdgeDist(Vertex, Visited&);
Graph Prims(Graph);
int CalcMaxSpanningWeight(Graph);
void FloydWarshall(Graph& G) {
    int size = G.size();

    // Initialize the distance matrix with the given graph
    vector<vector<int>> dist(G);

    // Apply Floyd-Warshall algorithm
    for (int k = 0; k < size; ++k) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                // If vertex k is an intermediate vertex on the shortest path from i to j
                // and the total distance is smaller than the current distance, update the value
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Update the graph with the shortest distances
    G = dist;
}

int main() {
    int size;
    cout << "Enter Vertex No: ";
    cin >> size;
    Graph G(size, Vertex(size, 0));
    cout << "Enter Matrix:" << endl;
    InputGraphMatrix(G);
    // cout << "Original Graph:" << endl; ShowGraph(G);
    // Graph MST = Prims(G);
    FloydWarshall(G); ShowGraph(G);
    // cout << "MST after Prims:" << endl; ShowGraph(MST);
    return 0;
}

void ShowGraph(Graph G){
    int size = G.size();
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
                cout << G[i][j] << " ";
        } cout << endl;
    }
}
void InputGraphMatrix(Graph& G) {
    for (auto& vtx : G) {
        for (auto& edge : vtx) {
            cin >> edge;
        }
    }
}

int FindMaxEdgeDist(Vertex vtx, Visited& Flag) {
    int max = INT_MIN;
    int v = -1, size = vtx.size();
    
    for (int j = 0; j < size; j++) {
        if (!Flag[j] && vtx[j]) {  // not in selected and there is an edge
            if (max < vtx[j]) {
                max = vtx[j];
                v = j;
            }
        }
    }
    return v;
}

Graph Prims(Graph G) {
    int size = G.size();
    Visited Flag(size, false);
    Graph result(size, Vertex(size, 0));
    int count = 0;
    Flag[0] = true; // Start with the first vertex
    int u, v;
    while (count < size - 1) {
        for (int i = 0; i < size; i++) {
            if (Flag[i]) {
                v = FindMaxEdgeDist(G[i], Flag);
                if(v != -1) u=i;
            }
        }
        if(u != -1 && v != -1) {
            result[u][v] = result[v][u] = G[u][v];
            Flag[v] = true;
        }
        count++;
    }

    return result;
}

int CalcMaxSpanningWeight(Graph G){
    int size = G.size(), w = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if(G[i][j]) w += G[i][j];
        }
    }
    return w;
}

// 5
// 0   10  5   5   INF 
// INF 0   5   5   5   
// INF INF 0   INF 10  
// INF INF INF 0   20  
// INF INF INF 5   0   

// 0 10 15 5 15
// INF 0 5 5 5
// INF INF 0 15 10
// INF INF INF 0 20
