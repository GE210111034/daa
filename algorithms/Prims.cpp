#include <bits/stdc++.h>
using namespace std;

typedef vector<int> Vertex;
typedef vector<Vertex> Graph;
typedef vector<pair<int, int>> Edge;
typedef vector<bool> Visited;

void ShowGraph(Graph);
void InputGraphMatrix(Graph&);
int FindMinEdgeDist(Vertex, Visited&);
Graph Prims(Graph);

int main() {
    int size;
    cout << "Enter Vertex No: ";
    cin >> size;
    Graph G(size, Vertex(size, 0));
    cout << "Enter Matrix:" << endl;
    InputGraphMatrix(G);
    cout << "Original Graph:" << endl;
    ShowGraph(G);
    Graph MST = Prims(G);
    cout << "MST after Prims:" << endl;
    ShowGraph(MST);
    return 0;
}

void ShowGraph(Graph G){
    int size = G.size();
    for(int i=0;i<size;i++)
    for(int j=0, w = G[i][j];j<i;j++,w = G[i][j])
        if(w != 0 && w != -1) cout << j << " -> " << i << ": " << w << endl;
 }
void InputGraphMatrix(Graph& G) {
    for (auto& vtx : G) {
        for (auto& edge : vtx) {
            cin >> edge;
        }
    }
}

int FindMinEdgeDist(Vertex vtx, Visited& Flag) {
    int min = INT_MAX;
    int v = -1, size = vtx.size();
    
    for (int j = 0; j < size; j++) {
        if (!Flag[j] && vtx[j]) {  // not in selected and there is an edge
            if (min > vtx[j]) {
                min = vtx[j];
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
                v = FindMinEdgeDist(G[i], Flag);
                if(v != -1) u=i;
            }
        }
        result[u][v] = result[v][u] = G[u][v];
        Flag[v] = true;
        count++;
    }

    return result;
}


// 0 3 0 1
// 3 0 1 0
// 0 1 0 2
// 1 0 2 0

// 0 1 0 2 0 
// 1 0 1 0 0 
// 0 1 0 1 0 
// 2 0 1 0 3 
// 0 0 0 3 0


// 0 1 0 0 0 0 
// 1 0 2 0 0 0 
// 0 2 0 3 0 15
// 0 0 3 0 4 0 
// 0 0 0 4 0 5 
// 0 0 15 0 5 0 

// {{0, 1, 0 ,0 ,0 ,0 },
// {1, 0, 2 ,0 ,0 ,0 },
// {0, 2, 0 ,3 ,0 ,15},
// {0, 0, 3 ,0 ,4 ,0 },
// {0, 0, 0 ,4 ,0 ,5 },
// {0, 0, 15, 0, 5, 0}}