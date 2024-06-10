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
    int toSearch;
    printf("Enter the element to search: ");
    scanf("%d", &toSearch);

    int flag = -1;
    // 0 -> Not Found;
    // 1 -> Found;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == toSearch)
        {
            flag = i;
        }
    }
    if (flag != -1)
    {
        printf("FOUND at index: %d", flag);
    }
    else
    {
        printf("Not Found!!");
    }
}