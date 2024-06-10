#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " | ";
    }
    cout << endl;
}

int quick_partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    do
    {
        i++;
    } while (arr[i] < pivot);

    while (i < j)
    {
        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[low], arr[j]);
    return j;
}

int qSort(int arr[], int low, int high)
{
    int j;
    if (low < high)
    {
        j = quick_partition(arr, low, high);
        qSort(arr, low, j - 1);
        qSort(arr, j + 1, high);
    }
}

int main()
{
    int size = 10;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }
    qSort(arr, 0, size - 1);
    display(arr, size);
    return 0;
}