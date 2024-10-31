#include <iostream>
#include <climits>
#include <vector>

using namespace std;

const int V = 3; 
int findMinDistance(int dist[], bool included[]) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < V; v++) {
        if (!included[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to print the constructed distance array
void printSolution(int dist[]) {
    cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << " \t\t " << dist[i] << "\n";
    }
}

// Function that implements Dijkstra's algorithm
void dijkstrasAlgo(int graph[V][V], int src) {
    int dist[V]; // Array to store the minimum distance from source
    bool included[V]; // Array to keep track of included nodes

    // Initialize all distances as INFINITE and included as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        included[i] = false;
    }

    dist[src] = 0; // Distance from source to itself is 0

    // Find the shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = findMinDistance(dist, included);
        included[u] = true;

        // Update the distance of all adjacent vertices of the selected vertex
        for (int v = 0; v < V; v++) {
            if (!included[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    printSolution(dist);
}

int main() {
    int graph[V][V];

    // User input for the adjacency matrix
    cout << "Enter the adjacency matrix (" << V << "x" << V << "):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    int src;
    cout << "Enter the source vertex (0 to " << V - 1 << "): ";
    cin >> src;

    // Perform Dijkstra's algorithm starting from the source vertex
    dijkstrasAlgo(graph, src);

    return 0;
}
