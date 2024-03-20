#include <stdio.h>
#include <stdbool.h>

#define V 3 // Number of vertices

void printSolution(int path[]) {
    printf("Hamiltonian Circuit: ");
    for (int i = 0; i < V; i++)
        printf("%d ", path[i]);
    printf("%d ", path[0]); // Print the first vertex again to complete the circuit
    printf("\n");
}

bool isSafe(int v, bool graph[V][V], int path[], int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return false;
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
    return true;
}

bool hamiltonianCircuitUtil(bool graph[V][V], int path[], int pos) {
    if (pos == V) {
        // Check if there is an edge from the last vertex to the first vertex
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }
    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            if (hamiltonianCircuitUtil(graph, path, pos + 1) == true)
                return true;
            path[pos] = -1; // Backtrack
        }
    }
    return false;
}

bool hamiltonianCircuit(bool graph[V][V]) {
    int path[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;
    path[0] = 0;
    if (hamiltonianCircuitUtil(graph, path, 1) == false) {
        printf("No Hamiltonian circuit exists\n");
        return false;
    }
    printSolution(path);
    return true;
}

int main() {
    bool graph[V][V];
    printf("Enter the adjacency matrix (1 for edge, 0 for no edge):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    hamiltonianCircuit(graph);
    return 0;
}
