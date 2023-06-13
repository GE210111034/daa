#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
typedef struct {
    int vertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;
void initializeGraph(Graph* graph, int vertices) {
    graph->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
}
void addEdge(Graph* graph, int src, int dest) {
    if (src >= 0 && src < graph->vertices && dest >= 0 && dest < graph->vertices) {
        graph->adjacencyMatrix[src][dest] = 1;
        graph->adjacencyMatrix[dest][src] = 1;
    }
}
int isCycleUtil(Graph* graph, int v, int visited[], int recursionStack[]) {
    visited[v] = 1;
    recursionStack[v] = 1;
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adjacencyMatrix[v][i] == 1)
            if (!visited[i] && isCycleUtil(graph, i, visited, recursionStack)) return 1;
            else if (recursionStack[i]) return 1;
        }
    }
    recursionStack[v] = 0;
    return 0;
}
int isCycleInGraph(Graph* graph) {
    int visited[MAX_VERTICES] = { 0 };
    int recursionStack[MAX_VERTICES] = { 0 };
    for (int i = 0; i < graph->vertices; i++) if (!visited[i]) if (isCycleUtil(graph, i, visited, recursionStack)) return 1;
    return 0;
}
int main() {
    printf("Enter the number of vertices in the graph: ");
    int vertices; scanf("%d", &vertices);
    Graph graph; initializeGraph(&graph, vertices);
    printf("Enter the adjacency matrix (0 or 1):\n");
    for (int i = 0; i < vertices; i++) for (int j = 0; j < vertices; j++) scanf("%d", &graph.adjacencyMatrix[i][j]);
    if (isCycleInGraph(&graph)) printf("Graph contains a cycle.\n");
    else printf("Graph does not contain a cycle.\n");
    return 0;
}

