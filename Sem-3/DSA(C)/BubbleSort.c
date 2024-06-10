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
    for (int i = 0; i < len; i++)
    {
        printf("%d, ", arr[i]);
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
