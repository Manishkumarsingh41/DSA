#include <stdio.h>
#include <limits.h>
#define MAX_VERTICES 100
void dijkstra(int cost[][MAX_VERTICES], int n, int source, int dist[]) {
    int min, min_index, i, j;
    for (i = 0; i < n; i++) {
        dist[i] = cost[source][i];
    }
    int visited[n];
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    for (i = 0; i < n; i++) {
        min = INT_MAX;
        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                min_index = j;
            }
        }
        visited[min_index] = 1;
        for (j = 0; j < n; j++) {
            if (!visited[j] && cost[min_index][j] != INT_MAX && dist[min_index] + cost[min_index][j] < dist[j]) {
                dist[j] = dist[min_index] + cost[min_index][j];
            }
        }
    }
}
int main() {
    int n, source, i, j;
    int cost[MAX_VERTICES][MAX_VERTICES];
    int dist[MAX_VERTICES];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = INT_MAX;
            }
        }
    }
    printf("Enter the source vertex: ");
    scanf("%d", &source);
    dijkstra(cost, n, source, dist);
    printf("Shortest distances from vertex %d:\n", source);
    for (i = 0; i < n; i++) {
        printf("Cost from %d to %d is %d\n", source, i, dist[i]);
    }
    return 0;
}