/*
Performing Quick Sort and Merge Sort
Author: Neeraj
Date: October 11, 2023
*/

#include <stdio.h>

// Function to merge two subarrays into a single sorted subarray
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    // Merge the two subarrays back into the original array
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[] and R[] if any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Recursive function to perform Merge Sort
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // Recursively divide and sort the left and right halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to perform the partition in Quick Sort
int partition(int arr[], int left, int right)
{
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j <= right - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;

    return i + 1;
}

// Recursive function to perform Quick Sort
void quickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int pivotIndex = partition(arr, left, right);

        // Recursively sort the elements before and after the pivot
        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);
    }
}

int main()
{
    int arr[] = {12, 11, 13, 6, 7, 5, 16, 3, 21, 1, 4, 2, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int choice;
    
    printf("-----------\n1. Quick Sort\n2. Merge Sort\n-----------\nEnter Your Choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Performing Quick Sort...\n");
        quickSort(arr, 0, n - 1);
        break;
    case 2:
        printf("Performing Merge Sort...\n");
        mergeSort(arr, 0, n - 1);
        break;
    default:
        printf("Invalid choice. Please enter 1 for Quick Sort or 2 for Merge Sort.\n");
        return 1;
    }

    printf("Sorted Array: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    return 0;
}