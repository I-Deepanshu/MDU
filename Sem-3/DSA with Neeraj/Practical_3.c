/*
Selection Sort and Bubble Sort
Author: Neeraj
Date: October 10, 2023
*/

#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int array[10], int n)
{
    int i, j, temp;
    for (i = 1; i <= n - 1; i++)
    {
        for (j = 1; j <= n - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void selection_sort(int array[10], int n)
{
    int i, j, temp, min;
    for (i = 1; i <= n - 1; i++)
    {
        min = i;
        for (j = i + 1; j <= n; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}

void main()
{
    int array[10], n, i, choice;
    void bubble_sort(int array[10], int n);
    void selection_sort(int array[10], int n);
    system("cls");
    printf("ENTER THE SIZE OF THE ARRAY:");
    scanf("%d", &n);
    printf("ENTER THE ELEMENTS OF THE ARRAY:\n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("___________________\n");
    printf("1.BUBBLE SORT\n");
    printf("2.SELECTION SORT\n");
    printf("___________________\n");
    printf("ENTER YOUR CHOICE:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        bubble_sort(array, n);
        printf("THE SORTED ARRAY IS:\n");
        for (i = 1; i <= n; i++)
        {
            printf("%d\t", array[i]);
        }
        break;
    case 2:
        selection_sort(array, n);
        printf("THE SORTED ARRAY IS:\n");
        for (i = 1; i <= n; i++)
        {
            printf("%d\t", array[i]);
        }
        break;
    default:
        printf("INVALID CHOICE");
    }
}