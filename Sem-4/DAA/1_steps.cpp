#include <iostream>
#include <vector>
using namespace std;

// Function to perform linear search
int linearSearch(vector<int> &arr, int target, int &steps)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        steps++; // Increment the step counter for each iteration
        if (arr[i] == target)
        {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if target not found
}

// Function to perform binary search
int binarySearch(vector<int> &arr, int target, int &steps)
{
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right)
    {
        steps++; // Increment the step counter for each iteration
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            return mid; // Return index if found
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1; // Return -1 if target not found
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 7;

    int linearSteps = 0;
    int linearIndex = linearSearch(arr, target, linearSteps);

    int binarySteps = 0;
    int binaryIndex = binarySearch(arr, target, binarySteps);

    if (linearIndex != -1)
    {
        cout << "Linear Search: Target found at -> " << linearIndex << endl;
        cout << "Steps: " << linearSteps << endl;
    }
    else
    {
        cout << "Linear Search: Target not found" << endl;
        cout << "Steps: " << linearSteps << endl;
    }

    if (binaryIndex != -1)
    {
        cout << "Binary Search: Target found at -> " << binaryIndex << endl;
        cout << "Steps: " << binarySteps << endl;
    }
    else
    {
        cout << "Binary Search: Target not found" << endl;
        cout << "Steps: " << binarySteps << endl;
    }

    return 0;
}

PS E:\GitHub\MDU\Sem-4\DAA> cd "e:\GitHub\MDU\Sem-4\DAA\" ; if ($?) { g++ 1_steps.cpp -o 1_steps } ; if ($?) { .\1_steps }
Linear Search: Target found at -> 6
Steps: 7
Binary Search: Target found at -> 6
Steps: 4