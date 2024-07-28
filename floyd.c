#include <stdio.h>
void floyd(int n, int cam[20][20]);
void printmat(int dist[20][20], int n);
void readmat();
void main() {
    readmat();
}
void readmat() {
    int cam[20][20], n, j, i;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cam[i][j]);
        }
    }
    floyd(n, cam);
}
void floyd(int n, int cam[20][20]) {
    int i, k, j, dist[20][20];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            dist[i][j] = cam[i][j];
        }
    }
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    printmat(dist, n);
}
void printmat(int dist[20][20], int n) {
    int i, j;
    printf("Matrix containing shortest distance between two vertices is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}