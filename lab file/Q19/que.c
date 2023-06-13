#include <stdio.h>
#define MAX_VERTICES 10
#define INFINITY 9999

void Dijkstra(int Graph[MAX_VERTICES][MAX_VERTICES], int vertex, int start) {
  int cost[MAX_VERTICES][MAX_VERTICES], distance[MAX_VERTICES], pred[MAX_VERTICES];
  int visited[MAX_VERTICES], count, mindistance, nextnode, i, j;// Creating cost matrix
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (Graph[i][j] == 0)
        cost[i][j] = INFINITY;
      else
        cost[i][j] = Graph[i][j];
  for (i = 0; i < n; i++) { distance[i] = cost[start][i]; pred[i] = start; visited[i] = 0; }
  distance[start] = 0; visited[start] = 1; count = 1;
  while (count < n - 1) {
    mindistance = INFINITY;
    for (i = 0; i < n; i++)
      if (distance[i] < mindistance && !visited[i]) mindistance = distance[i], nextnode = i;
    visited[nextnode] = 1;
    for (i = 0; i < n; i++)
      if (!visited[i])
        if (mindistance + cost[nextnode][i] < distance[i]) {
          distance[i] = mindistance + cost[nextnode][i];
          pred[i] = nextnode;
        } count++;
  }
  // Printing the distance
  for (i = 0; i < n; i++)
    if (i != start) {
      printf("\nDistance from source to %d: %d", i, distance[i]);
    }
}
int main() {
    printf("Enter the number of vertices in the graph: ");
    int vertices; scanf("%d", &vertices);
    int graph[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency matrix (space-separated):\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) scanf("%d", &graph[i][j]);
    }
    printf("Enter Akshay's house location: ");
    int start; scanf("%d", &start);
    Dijkstra(graph, vertices, start - 1);
    return 0;
}

1 : 0
2 3 1 : 3
3 1 : 1
4 3 1 : 3
5 2 3 1 : 7