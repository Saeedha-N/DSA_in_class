#include <iostream>
#include <climits>
#include <vector>
#include <iomanip>
using namespace std;

#define V 6  //V = nuumber of vertices in the graph

int min_distance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printPath(vector<int> parent, int j) {
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);
    cout << " -> " << j;
}

void printSolution(int dist[], vector<int> parent, int source) {
    int sum = 0;
    cout << "City\t\t\tTime\t\tPath\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t\t\t" << dist[i] << "\t\t" << source;
        printPath(parent, i);
        cout << endl;

        if (i != source) {
            sum += dist[i];
        }
    }

    double average = static_cast<double>(sum) / (V - 1);
    cout << fixed << setprecision(2);
    cout << "Average time from source city to all others cities = " << average << "\n" << endl;
}

void dijkstra(int graph[V][V], int source) {
    int dist[V];
    bool sptSet[V];
    vector<int> parent(V, -1); // To store the parent nodes of the shortest path

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[source] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = min_distance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u; //Update parent for the shortest path
            }
        }
    }

    printSolution(dist, parent, source);
}

int main() {
    int graph[V][V] = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };
    
    for (int i =0 ; i < 6 ; i ++ ) {
        int source = i;
            cout<< "Source City = "<< i <<""<<endl;
            dijkstra(graph, source);
        
    }

    return 0;
}