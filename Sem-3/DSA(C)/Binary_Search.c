#include <stdio.h>
#include <conio.h>

void main()
{
    int len;
    printf("Enter the length of Array: ");
    scanf("%d", &len);
    int arr[len];

    printf("Enter the elements of the array: \n");
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &arr[i]);
    }

    // ? SORTING
    bubbleSort(arr, len);

    int toSearch;
    printf("Enter the element to search: ");
    scanf("%d", &toSearch);

    int res = binarySearch(arr, 0, len - 1, toSearch);
    if (res == -1)
    {
        printf("Not Found!");
    }
    else
    {
        printf("Found at: %d", res);
    }
}

void bubbleSort(int arr[], int len)

{
    int temp;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int l, int r, int toSearch)
{
    if (r >= l)
    {

        int mid;
        mid = l + r / 2;
        if (arr[mid] == toSearch)
        {
            return mid;
        }
        else if (arr[mid] > toSearch)
        {
            return binarySearch(arr, l, mid - 1, toSearch);
        }
        else
        {
            return binarySearch(arr, mid + 1, r, toSearch);
        }
    }
    else
    {
        return -1;
    }
}

