#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_VERTICES 100
typedef struct {
    int vertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;
void initializeGraph(Graph* graph, int vertices) {
    graph->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) graph->adjacencyMatrix[i][j] = 0;
    }
}
void addEdge(Graph* graph, int src, int dest) {
    if (src >= 0 && src < graph->vertices && dest >= 0 && dest < graph->vertices) {
        graph->adjacencyMatrix[src][dest] = 1;
        graph->adjacencyMatrix[dest][src] = 1;
    }
}
bool isBipartite(Graph* graph) {
    int color[MAX_VERTICES] = {0}; int queue[MAX_VERTICES];
    int front = 0, rear = 0, start = 0; // Start vertex for BFS
    color[start] = 1; // Color the start vertex as 1
    queue[rear++] = start; // Enqueue the start vertex
    while (front != rear) { int current = queue[front++];
        // Check if there's a self-loop, i.e., an edge from a vertex to itself
        if (graph->adjacencyMatrix[current][current] == 1) return false; // Process neighbors of the current vertex
        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjacencyMatrix[current][i] == 1) {
                if (color[i] == 0) {// If the neighbor is not colored, assign a different color and enqueue
                    color[i] = (color[current] == 1) ? 2 : 1; queue[rear++] = i;
                }// If the neighbor has the same color as the current vertex, not bipartite
                else if (color[i] == color[current]) return false;
            }
        }
    }
    return true; // Graph is bipartite
}

int main() {
    printf("Enter the number of vertices in the graph: ");
    int vertices;     scanf("%d", &vertices);
    Graph graph; initializeGraph(&graph, vertices);
    printf("Enter the adjacency matrix (0 or 1):\n");
    for (int i = 0; i < vertices; i++) for (int j = 0; j < vertices; j++) scanf("%d", &graph.adjacencyMatrix[i][j]);
    if (isBipartite(&graph)) printf("The graph is bipartite.\n");
    else printf("The graph is not bipartite.\n");
    return 0;
}

// gitpod /workspace/daa (main) 
// $ cd "/workspace/daa/" && g++ a.cpp -o a && "/workspace/daa/"a
// Enter the number of vertices in the graph: 5
// Enter the adjacency matrix (0 or 1):
// 0 1 0 1 0
// 1 0 1 0 1
// 0 1 0 1 0
// 1 0 1 0 1
// 0 1 0 1 0
// The graph is bipartite.
