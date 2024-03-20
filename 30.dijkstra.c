#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int minDistance(int distances[], int visited[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (visited[v] == 0 && distances[v] <= min) {
            min = distances[v];
            min_index = v;
        }
    }
    return min_index;
}
void printSolution(int distances[], int V) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i, distances[i]);
}
void dijkstra(int graph[100][100], int source, int V) {
    int distances[V]; 
    int visited[V];   
    for (int i = 0; i < V; i++) {
        distances[i] = INT_MAX;
        visited[i] = 0;
    }
    distances[source] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(distances, visited, V);
        visited[u] = 1;
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && distances[u] != INT_MAX && distances[u] + graph[u][v] < distances[v])
                distances[v] = distances[u] + graph[u][v];
        }
    }
    printSolution(distances, V);
}
int main() {
	int V;
	printf("enter size of graph");
	scanf("%d",&V);
    int graph[100][100];
    printf("enter elements \n ");
	for(int i=0;i<V;i++) 
	{
	for(int j=0;j<V;j++)  
	{
		scanf("%d",&graph[i][j]);
	}
	printf("\n");
}
    int source = 0;
    dijkstra(graph, source, V);
    return 0;
}
/*{
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };*/