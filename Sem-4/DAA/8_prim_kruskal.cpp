#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int source;
    int destination;
    int weight;
};

// Structure to represent a graph
struct Graph {
    int V; // Number of vertices
    int E; // Number of edges
    vector<Edge> edges; // Vector to store edges
};

// Function to create a new graph
Graph createGraph(int V, int E, vector<Edge>& edges) {
    Graph graph;
    graph.V = V;
    graph.E = E;
    graph.edges = edges;
    return graph;
}

// Function to compare edges based on their weights
bool compareEdges(const Edge& edge1, const Edge& edge2) {
    return edge1.weight < edge2.weight;
}

// Function to find the parent of a vertex in a set
int findParent(int vertex, vector<int>& parent) {
    if (parent[vertex] == -1)
        return vertex;
    return findParent(parent[vertex], parent);
}

// Function to perform union of two sets
void performUnion(int x, int y, vector<int>& parent) {
    int xSet = findParent(x, parent);
    int ySet = findParent(y, parent);
    parent[xSet] = ySet;
}

// Function to find the minimum spanning tree using Kruskal's algorithm
void kruskalMST(const Graph& graph) {
    // Sort edges by weight
    vector<Edge> sortedEdges = graph.edges;
    sort(sortedEdges.begin(), sortedEdges.end(), compareEdges);

    int V = graph.V;
    vector<int> parent(V, -1); // Array to store parent of each vertex
    vector<Edge> mst; // Minimum spanning tree

    int edgeCount = 0; // Counter to track number of edges in MST
    int index = 0; // Index to iterate over sorted edges

    // Loop until we have V-1 edges in MST
    while (edgeCount < V - 1 && index < graph.E) {
        Edge nextEdge = sortedEdges[index++];
        int sourceParent = findParent(nextEdge.source, parent);
        int destinationParent = findParent(nextEdge.destination, parent);

        // If including this edge does not cause cycle, include it in MST
        if (sourceParent != destinationParent) {
            mst.push_back(nextEdge);
            performUnion(sourceParent, destinationParent, parent);
            edgeCount++;
        }
    }

    // Print the edges of MST
    cout << "Edges of Minimum Spanning Tree using Kruskal's algorithm:" << endl;
    for (const Edge& edge : mst) {
        cout << edge.source << " - " << edge.destination << " : " << edge.weight << endl;
    }
}

// Function to find the minimum spanning tree using Prim's algorithm
void primMST(const Graph& graph) {
    int V = graph.V;
    vector<int> parent(V, -1); // Array to store parent of each vertex
    vector<bool> inMST(V, false); // Array to track if vertex is already in MST
    vector<int> key(V, INT_MAX); // Key values used to pick minimum weight edge

    // Priority queue to store vertices based on their key values
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Start with vertex 0
    pq.push(make_pair(0, 0));
    key[0] = 0; // Key value of first vertex is 0

    while (!pq.empty()) {
        int u = pq.top().second; // Extract minimum key vertex
        pq.pop();

        inMST[u] = true; // Include vertex in MST

        // Update key value and parent index of adjacent vertices of the picked vertex
        for (const Edge& edge : graph.edges) {
            int v = (edge.source == u) ? edge.destination : (edge.destination == u) ? edge.source : -1;
            if (v != -1 && !inMST[v] && edge.weight < key[v]) {
                parent[v] = u;
                key[v] = edge.weight;
                pq.push(make_pair(key[v], v));
            }
        }
    }

    // Print the edges of MST
    cout << "\nEdges of Minimum Spanning Tree using Prim's algorithm:" << endl;
    for (int i = 1; i < V; ++i) {
        cout << parent[i] << " - " << i << " : " << key[i] << endl;
    }
}

int main() {
    // Graph:
    //      2    3
    //  (0)---(1)---(2)
    //   |    /  \   | 4
    //   |   /    \  |
    // 5 |  /  6   \ | 1
    //   | /        \|
    //  (3)---------(4)
    //      7
    int V = 5; // Number of vertices
    int E = 7; // Number of edges
    vector<Edge> edges = {
        {0, 1, 2},
        {0, 3, 5},
        {1, 2, 3},
        {1, 3, 6},
        {1, 4, 4},
        {2, 4, 1},
        {3, 4, 7}
    };

    // Create graph
    Graph graph = createGraph(V, E, edges);

    // Find Minimum Spanning Tree using Kruskal's algorithm
    kruskalMST(graph);

    // Find Minimum Spanning Tree using Prim's algorithm
    primMST(graph);

    return 0;
}


// Edges of Minimum Spanning Tree using Kruskal's algorithm:
// 2 - 4 : 1
// 0 - 1 : 2
// 1 - 2 : 3
// 0 - 3 : 5

// Edges of Minimum Spanning Tree using Prim's algorithm:
// 0 - 1 : 2
// 1 - 2 : 3
// 0 - 3 : 5
// 2 - 4 : 1

//      2    3
//  (0)---(1)---(2)
//   |           | 4
//   |           |
// 5 |           | 1
//   |           |
//  (3)         (4)