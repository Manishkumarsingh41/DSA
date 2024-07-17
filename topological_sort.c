#include <stdio.h>
#include <stdlib.h>
#define V 6
void topologicalSortUtil(int graph[V][V], int v, int visited[], int stack[], int *top)
{
    visited[v] = 1;
    for (int i = 0; i < V; i++)
    {
        if (graph[v][i] == 1 && !visited[i])
            topologicalSortUtil(graph, i, visited, stack, top);
    }
    stack[(*top)++] = v;
}
void topologicalSort(int graph[V][V])
{
    int visited[V];
    int stack[V];
    int top = 0;
    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
    }
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            topologicalSortUtil(graph, i, visited, stack, &top);
    }
    for (int i = V - 1; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}
int main()
{
    int graph[V][V] = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}};
    topologicalSort(graph);
    return 0;
}
