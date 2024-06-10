#include <iostream>
#include <vector>
using namespace std;

// Merge function for Merge Sort
void merge(vector<int>& arr, int left, int mid, int right, int& mergeSteps) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    vector<int> L(n1), R(n2);

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        mergeSteps++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        mergeSteps++;
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        mergeSteps++;
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort function
void mergeSort(vector<int>& arr, int left, int right, int& mergeSteps) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid, mergeSteps);
        mergeSort(arr, mid + 1, right, mergeSteps);

        // Merge the sorted halves
        merge(arr, left, mid, right, mergeSteps);
    }
}

// Partition function for Quick Sort
int partition(vector<int>& arr, int low, int high, int& quickSteps) {
    int pivot = arr[high];
    int i = low - 1; // Index of smaller element

    for (int j = low; j < high; j++) {
        quickSteps++;
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(vector<int>& arr, int low, int high, int& quickSteps) {
    if (low < high) {
        // Partitioning index
        int pi = partition(arr, low, high, quickSteps);

        // Separate sorting of elements before and after partition
        quickSort(arr, low, pi - 1, quickSteps);
        quickSort(arr, pi + 1, high, quickSteps);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    cout << "Original array: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    // Merge Sort
    vector<int> mergeArr = arr;
    int mergeSteps = 0;
    mergeSort(mergeArr, 0, n - 1, mergeSteps);
    cout << "Array sorted using Merge Sort: ";
    for (int x : mergeArr) {
        cout << x << " ";
    }
    cout << endl;
    cout << "Merge Sort took " << mergeSteps << " steps." << endl;

    // Quick Sort
    vector<int> quickArr = arr;
    int quickSteps = 0;
    quickSort(quickArr, 0, n - 1, quickSteps);
    cout << "Array sorted using Quick Sort: ";
    for (int x : quickArr) {
        cout << x << " ";
    }
    cout << endl;
    cout << "Quick Sort took " << quickSteps << " steps." << endl;

    return 0;
}