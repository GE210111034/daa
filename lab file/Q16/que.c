#include <stdio.h>
#define MAX_VERTICES 100
typedef struct {
    int vertices;
    int isDirected;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;
void initializeGraph(Graph* graph, int vertices, int isDirected) {
    graph->vertices = vertices;
    graph->isDirected = isDirected;
    for (int i = 0; i < vertices; i++) for (int j = 0; j < vertices; j++) graph->adjacencyMatrix[i][j] = 0;
}
void addEdge(Graph* graph, int src, int dest) {
    if (src >= 0 && src < graph->vertices && dest >= 0 && dest < graph->vertices) {
        graph->adjacencyMatrix[src][dest] = 1;
        if (!graph->isDirected) graph->adjacencyMatrix[dest][src] = 1;
    }
}
int dfs(Graph* graph, int start, int end, int visited[]) {
    visited[start] = 1;
    if (start == end) return 1;
    for (int i = 0; i < graph->vertices; i++)
        if (graph->adjacencyMatrix[start][i] == 1 && !visited[i] && dfs(graph, i, end, visited)) return 1;
    return 0;
}
int isPathExists(Graph* graph, int start, int end) {
    int visited[MAX_VERTICES] = {0};
    return dfs(graph, start - 1, end - 1, visited);
}

int main() {
    printf("Enter the number of vertices in the graph: ");
    int vertices; scanf("%d", &vertices);
    Graph graph; initializeGraph(&graph, vertices, 0);
    printf("Enter the adjacency matrix (0 or 1):\n");
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++) scanf("%d", &graph.adjacencyMatrix[i][j]);
    printf("Enter the start and end vertices to check if a path exists: ");
    int start, end; scanf("%d%d", &start, &end);
    if (isPathExists(&graph, start, end)) printf("Path exists between the given vertices.\n");
    else printf("Path does not exist between the given vertices.\n");
    return 0;
}
