#include <iostream>
#include <vector>

using namespace std;

// Structure to represent an item
struct Item {
    int weight;
    int value;
};

// Function to solve 0/1 Knapsack problem using dynamic programming
int knapsack(int capacity, const vector<Item>& items, vector<Item>& selectedItems) {
    int n = items.size();

    // Create a 2D array to store the maximum value that can be obtained for each sub-problem
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Fill the dp table bottom-up
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            // If the current item can be included
            if (items[i - 1].weight <= w) {
                // Choose the maximum value between including and excluding the current item
                dp[i][w] = max(items[i - 1].value + dp[i - 1][w - items[i - 1].weight], dp[i - 1][w]);
            } else {
                // If the current item cannot be included, copy the value from the previous row
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Trace back to find the selected items
    int totalWeight = capacity;
    for (int i = n; i > 0 && totalWeight > 0; --i) {
        if (dp[i][totalWeight] != dp[i - 1][totalWeight]) {
            selectedItems.push_back(items[i - 1]);
            totalWeight -= items[i - 1].weight;
        }
    }

    // Return the maximum value that can be obtained with the given capacity
    return dp[n][capacity];
}

int main() {
    // Example items
    vector<Item> items = {
        {2, 1},
        {3, 2},
        {4, 5},
        {5, 6}
    };
    int capacity = 8;

    // Solve the knapsack problem and print the result
    vector<Item> selectedItems;
    int maxValue = knapsack(capacity, items, selectedItems);
    cout << "Maximum value that can be obtained: " << maxValue << endl;

    // Print the selected items
    cout << "Items included in the knapsack:" << endl;
    for (const Item& item : selectedItems) {
        cout << "Weight: " << item.weight << ", Profit: " << item.value << endl;
    }

    return 0;
}