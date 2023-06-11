#include <bits/stdc++.h>
using namespace std;

typedef vector<int> Vertex;
typedef vector<Vertex> Graph;
typedef vector<pair<int, int>> Edge;
typedef vector<bool> Visited;

void ShowGraph(Graph);
void InputGraphMatrix(Graph&);
void floydWarshall(Graph&);

int main() {
    int size;
    cout << "Enter Vertex No: ";
    cin >> size;
    Graph G(size, Vertex(size, 0));
    cout << "Enter Matrix:" << endl;
    InputGraphMatrix(G);
    cout << "Original Graph:" << endl;
    ShowGraph(G);

    floydWarshall(G);

    return 0;
}

void ShowGraph(Graph G) {
    int size = G.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (G[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << G[i][j] << " ";
        }
        cout << endl;
    }
}

void InputGraphMatrix(Graph& G) {
    int size = G.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> G[i][j];
            if (G[i][j] == 0)
                G[i][j] = INT_MAX;
        }
    }
}

void floydWarshall(Graph G) {
    int size = G.size();
    Graph dist = G;

    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    cout << "Shortest Path Matrix:" << endl;
    ShowGraph(dist);
}
