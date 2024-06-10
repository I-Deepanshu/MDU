#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent items
struct Item {
    int value;
    int weight;
    double ratio; // Value per unit weight
};

// Function to compare items based on their ratios
bool compareItems(const Item& item1, const Item& item2) {
    return item1.ratio > item2.ratio;
}

// Function to solve fractional knapsack problem
double fractionalKnapsack(int capacity, vector<Item>& items, vector<int>& selectedItems) {
    // Sort items based on their ratios (value per unit weight)
    sort(items.begin(), items.end(), compareItems);

    double totalValue = 0.0;

    for (const Item& item : items) {
        // If item can be fully included
        if (capacity >= item.weight) {
            totalValue += item.value;
            capacity -= item.weight;
            selectedItems.push_back(item.weight); // Add selected item's weight
        } else { // If item can only be partially included
            totalValue += (static_cast<double>(capacity) / item.weight) * item.value;
            selectedItems.push_back(capacity); // Add remaining capacity
            break; // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    // Example items
    vector<Item> items = {
        {10, 2, 0},
        {5, 3, 0},
        {15, 5, 0},
        {7, 7, 0},
        {6, 1, 0},
        {18, 4, 0},
        {3, 1, 0},
    };

    int capacity = 15; // Knapsack capacity

    // Calculate ratios (value per unit weight) for each item
    for (Item& item : items) {
        item.ratio = static_cast<double>(item.value) / item.weight;
    }

    vector<int> selectedItems; // To store selected items

    double maxValue = fractionalKnapsack(capacity, items, selectedItems);

    cout << "Maximum value that can be obtained: " << maxValue << endl;

    cout << "Selected items and their weights:" << endl;
    for (size_t i = 0; i < selectedItems.size(); ++i) {
        cout << "Item " << i+1 << ": ";
        if (selectedItems[i] == items[i].weight) {
            cout << "Whole item selected (weight: " << selectedItems[i] << ")" << endl;
        } else {
            cout << "Partial item selected (weight: " << selectedItems[i] << ")" << endl;
        }
    }

    return 0;
}
