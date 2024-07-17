#include <stdio.h>
#include <limits.h>
#define V_MAX 100
int minKey(int key[], int mstSet[], int V)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}
void printMST(int parent[], int n, int graph[V_MAX][V_MAX], int V)
{
    printf("Edge Weight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d %d \n", parent[i], i, graph[i][parent[i]]);
}
void primMST(int graph[][V_MAX], int V)
{
    int parent[V_MAX];
    int key[V_MAX];
    int mstSet[V_MAX];
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = 0;
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet, V);
        mstSet[u] = 1;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    printMST(parent, V, graph, V);
}
int main()
{
    int V, E;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);
    int graph[V_MAX][V_MAX];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            graph[i][j] = 0;
        }
    }
    printf("Enter the source vertex, destination vertex, and weight for each edge:\n");
    for (int i = 0; i < E; i++)
    {
        int source, dest, weight;
        scanf("%d %d %d", &source, &dest, &weight);
        graph[source][dest] = weight;
        graph[dest][source] = weight;
    }
    primMST(graph, V);
    return 0;
}
