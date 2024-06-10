#include <iostream>
#include <vector>
using namespace std;

class DisjointSets {
private:
    vector<int> parent;
public:
    DisjointSets(int n) {
        parent.resize(n);
        // Initialize each element's parent as itself
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    // Find operation: Find the root of the set to which x belongs
    int find(int x) {
        if (parent[x] != x) {
            // Path compression: Set parent of x to its root
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Union operation: Merge the sets containing x and y
    void Union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }
};

int main() {
    int n = 6; // Number of elements
    DisjointSets ds(n);

    ds.Union(0, 1);
    ds.Union(1, 2);
    ds.Union(3, 4);

    // Check if two elements belong to the same set
    cout << "Are 1 and 2 in the same set? " << (ds.find(1) == ds.find(2) ? "Yes" : "No") << endl;
    cout << "Are 1 and 3 in the same set? " << (ds.find(1) == ds.find(3) ? "Yes" : "No") << endl;
    cout << "Are 0 and 5 in the same set? " << (ds.find(0) == ds.find(5) ? "Yes" : "No") << endl;

    return 0;
}