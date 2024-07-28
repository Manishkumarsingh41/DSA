#include <stdio.h>

void wrshl(int n, int a[20][20]) {
    int i, j, k, m1[20][20], m2[20][20];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            m1[i][j] = a[i][j];
        }
    }

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                m2[i][j] = (m1[i][j] || (m1[i][k] && m1[k][j]));
            }
        }

        for (i = 0; i < n; i++) {
                       for (j = 0; j < n; j++) {
                m1[i][j] = m2[i][j];
            }
        }
    }

    printf("Transitive closure of the given matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", m1[i][j]);
        }
        printf("\n");
    }
}

void readmat() {
    int a[20][20], n, i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    wrshl(n, a);
}

void main() {
    readmat();
}