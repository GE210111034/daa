#include <stdio.h>

#define INFINITY 9999
#define MAX_VERTICES 10

void bellmanFord(int Graph[][MAX_VERTICES], int numVertices);
void displayMatrix(int matrix[][MAX_VERTICES], int numVertices);

int main() {
    int numVertices;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the adjacency matrix (space-separated):\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    bellmanFord(graph, numVertices);

    return 0;
}

void bellmanFord(int Graph[][MAX_VERTICES], int numVertices) {
    int distance[MAX_VERTICES][MAX_VERTICES];

    // step 1: initialize distance matrix
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            distance[i][j] = Graph[i][j];
        }
    }

    // step 2: relax edges |V| - 1 times
    for (int k = 0; k < numVertices; k++) {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                if (distance[i][k] != INFINITY && distance[k][j] != INFINITY &&
                    distance[i][j] > distance[i][k] + distance[k][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }

    // print the distance matrix
    printf("Shortest path matrix:\n");
    displayMatrix(distance, numVertices);
}

void displayMatrix(int matrix[][MAX_VERTICES], int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (matrix[i][j] == INFINITY) {
                printf("INF ");
            } else {
                printf("%d ", matrix[i][j]);
            }
        }
        printf("\n");
    }
}
