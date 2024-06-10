#include <iostream>
#include <vector>
using namespace std;

// Iterative Binary Search
int iterativeBinarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid; // Element found, return its index
        } else if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Element not found
}

// Recursive Binary Search
int recursiveBinarySearch(vector<int>& arr, int target, int left, int right) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid; // Element found, return its index
        } else if (arr[mid] < target) {
            return recursiveBinarySearch(arr, target, mid + 1, right); // Search in the right half
        } else {
            return recursiveBinarySearch(arr, target, left, mid - 1); // Search in the left half
        }
    }
    return -1; // Element not found
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 13;

    // Iterative Binary Search
    int iterativeIndex = iterativeBinarySearch(arr, target);
    if (iterativeIndex != -1) {
        cout << "Iterative Binary Search: Element " << target << " found at index " << iterativeIndex << endl;
    } else {
        cout << "Iterative Binary Search: Element " << target << " not found." << endl;
    }

    // Recursive Binary Search
    int recursiveIndex = recursiveBinarySearch(arr, target, 0, arr.size() - 1);
    if (recursiveIndex != -1) {
        cout << "Recursive Binary Search: Element " << target << " found at index " << recursiveIndex << endl;
    } else {
        cout << "Recursive Binary Search: Element " << target << " not found." << endl;
    }

    return 0;
}