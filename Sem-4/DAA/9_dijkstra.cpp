#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <stack>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int destination;
    int weight;
};

// Function to add an edge to the graph
void addEdge(vector<vector<Edge>>& graph, int source, int destination, int weight) {
    graph[source].push_back({destination, weight});
}

// Function to find the shortest paths from a single source vertex to all other vertices using Dijkstra's algorithm
void dijkstraShortestPaths(vector<vector<Edge>>& graph, int source) {
    int V = graph.size(); // Number of vertices

    // Initialize distances to all vertices as infinite
    vector<int> distances(V, INT_MAX);

    // Initialize parent of each vertex
    vector<int> parent(V, -1);

    // Create a priority queue to store vertices with their distances from the source
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Initialize distance of source vertex to 0
    distances[source] = 0;
    pq.push({0, source}); // Push source vertex to priority queue

    // Process vertices one by one
    while (!pq.empty()) {
        int u = pq.top().second; // Extract minimum distance vertex from priority queue
        pq.pop();

        // Update distances of adjacent vertices of the picked vertex
        for (const Edge& edge : graph[u]) {
            int v = edge.destination;
            int weight = edge.weight;

            // If there is a shorter path to v through u
            if (distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                parent[v] = u;
                pq.push({distances[v], v});
            }
        }
    }

    // Print shortest paths from source vertex to all other vertices
    cout << "Shortest paths from source vertex " << source << " to all other vertices:" << endl;
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << ": ";
        if (distances[i] == INT_MAX) {
            cout << "No path exists" << endl;
        } else {
            // Print shortest path
            stack<int> path;
            int current = i;
            while (current != -1) {
                path.push(current);
                current = parent[current];
            }
            while (!path.empty()) {
                cout << path.top() << " ";
                path.pop();
            }
            cout << "(Distance: " << distances[i] << ")" << endl;
        }
    }
}

int main() {
    // Example graph:
    //    (0)---2---(1)
    //     | \       |
    //     |  4      | 1
    //     | /       |
    //    (2)---3---(3)
    int V = 4; // Number of vertices
    vector<vector<Edge>> graph(V); // Adjacency list representation of graph

    // Add edges to the graph
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 2, 4);
    addEdge(graph, 0, 3, 1);
    addEdge(graph, 1, 3, 3);
    addEdge(graph, 2, 3, 2);

    int source = 0; // Source vertex

    // Find shortest paths from source vertex using Dijkstra's algorithm
    dijkstraShortestPaths(graph, source);

    return 0;
}