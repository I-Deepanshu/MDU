/*
Program to Implement Heap Sort and Insertion Sort
Author: Neeraj
Date: October 11, 2023
*/

#include <stdio.h>
#include <stdlib.h>

void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    // If largest is not root
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--)
    {
        // Move current root to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void insertion_sort(int arr[], int n)
{
    int i, j, temp;
    for (i = 1; i <= n; i++)
    {
        temp = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1], that are greater than temp, to one position ahead of their current position
        while (temp < arr[j] && j >= 0)     
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void main()
{
    int arr[10], n, i, choice;
    void heap_sort(int arr[], int n);
    void insertion_sort(int arr[], int n);
    system("cls");
    printf("ENTER THE SIZE OF THE ARRAY:");
    scanf("%d", &n);
    printf("ENTER THE ELEMENTS OF THE ARRAY:\n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("___________________\n");
    printf("1.HEAP SORT\n");
    printf("2.INSERTION SORT\n");
    printf("___________________\n");
    printf("ENTER YOUR CHOICE:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        heap_sort(arr, n);
        printf("THE SORTED ARRAY IS:\n");
        for (i = 1; i <= n; i++)
        {
            printf("%d\t", arr[i]);
        }
        break;
    case 2:
        insertion_sort(arr, n);
        printf("THE SORTED ARRAY IS:\n");
        for (i = 1; i <= n; i++)
        {
            printf("%d\t", arr[i]);
        }
        break;
    default:
        printf("INVALID CHOICE");
        break;
    }
    return 0;
}