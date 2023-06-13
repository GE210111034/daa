#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> Graph;
const int INF = 1e9;
void ShowShortestPath(const vector<int>& path, const int destination) {
    if (path[destination] == -1) {
        cout << "No path exists from source to destination." << endl; return;
    }
    vector<int> shortestPath;
    int vertex = destination;
    while (vertex != -1) shortestPath.push_back(vertex), vertex = path[vertex];
    cout << "Shortest path from source to destination: ";
    for (int i = shortestPath.size() - 1; i >= 0; --i) {
        cout << shortestPath[i]; if (i != 0) cout << " -> ";
    } cout << endl;
}
int ShortestPathWithKEdges(Graph& graph, int source, int destination, int k) {
    int numVertices = graph.size();
    vector<vector<int>> dp(numVertices, vector<int>(k + 1, INF));
    vector<vector<int>> parent(numVertices, vector<int>(k + 1, -1));
    dp[source][0] = 0;
    for (int e = 1; e <= k; ++e) {
        for (int v = 0; v < numVertices; ++v) {
            for (int u = 0; u < numVertices; ++u) { int weight = graph[u][v];
                if (weight != 0 && dp[u][e - 1] != INF && dp[u][e - 1] + weight < dp[v][e]) {
                    dp[v][e] = dp[u][e - 1] + weight; parent[v][e] = u;
                }
            }
        }
    }
    ShowShortestPath(parent[destination], destination);
    return dp[destination][k];
}
int main() {
    cout << "Enter the number of vertices: ";
    int numVertices; cin >> numVertices;
    Graph graph(numVertices, vector<int>(numVertices, 0));
    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < numVertices; ++i) for (int j = 0; j < numVertices; ++j) cin >> graph[i][j];
    cout << "Enter the source vertex: ";
    int source, destination, k; cin >> source;
    cout << "Enter the destination vertex: "; cin >> destination;
    cout << "Enter the number of edges on the path: "; cin >> k;
    int shortestPathWeight = ShortestPathWithKEdges(graph, source - 1, destination - 1, k);
    cout << "Weight of shortest path from (" << source << "," << destination << ") with " << k << " edges: " << shortestPathWeight << endl;
    return 0;
}
