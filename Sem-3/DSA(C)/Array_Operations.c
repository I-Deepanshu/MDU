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
    void fun(int arr[], int len);
    fun(arr, len);
}

void fun(int arr[], int len)
{
    int op;
    printf("Enter the operation to perform:\n1. Replace Element\n2. Delete Element\n3. Display Elements\n-> ");
    scanf("%d", &op);

    int index;
    switch (op)
    {
    case 1:
        printf("Enter the index of element to replace: ");
        scanf("%d", &index);
        int num;
        printf("Enter the value to insert: ");
        scanf("%d", &num);
        arr[index] = num;
        for (int i = 0; i < len; i++)
        {
            printf("%d, ", arr[i]);
        }
        break;
    case 2:
        // int index1;
        printf("Enter the index of element to delete: ");
        scanf("%d", &index);
        len = len - 1;
        for (int i = index; i < len; i++)
        {
            arr[i] = arr[i + 1];
        }
        for (int i = 0; i < len; i++)
        {
            printf("%d, ", arr[i]);
        }
        break;
    case 3:
        for (int i = 0; i < len; i++)
        {
            printf("%d, ", arr[i]);
        }
        break;
    default:
        printf("Invalid Choice!!");
        break;
    }
}