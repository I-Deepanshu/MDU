#include <stdio.h>

int linearSearch(int arr[], int size)
{
    int searchElement;
    printf("Enter the element you want to search for: ");
    scanf("%d", &searchElement);

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == searchElement)
        {
            printf("Element found at index %d\n", i);
            return i;
        }
    }

    printf("Element not found\n");
    return -1;
}

int main()
{
    int arr[] = {5, 10, 15, 20, 25};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Array elements: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    linearSearch(arr, size);

    return 0;
}