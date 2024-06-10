#include <stdio.h>
#include <conio.h>

int main()
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
    selectionSort(arr, len);
    for (int i = 0; i < len; i++)
    {
        printf("%d, ", arr[i]);
    }
}

void selectionSort(int arr[], int len)
{
    int min, temp;
    for (int i = 0; i < len; i++)
    {
        min = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
            if (min != i)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}