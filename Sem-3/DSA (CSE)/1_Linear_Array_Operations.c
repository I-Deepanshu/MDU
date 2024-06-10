#include <stdio.h>

#define MAX_SIZE 100

void displayArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertElement(int arr[], int *size, int position, int element) {
    if (*size >= MAX_SIZE) {
        printf("Array is full. Cannot insert element.\n");
        return;
    }
    if (position < 0 || position > *size) {
        printf("Invalid position. Cannot insert element.\n");
        return;
    }
    for (int i = *size - 1; i >= position; i--)
        arr[i + 1] = arr[i];
    arr[position] = element;
    (*size)++;
    printf("Element inserted successfully.\n");
}

void deleteElement(int arr[], int *size, int position) {
    if (*size <= 0) {
        printf("Array is empty. Cannot delete element.\n");
        return;
    }
    if (position < 0 || position >= *size) {
        printf("Invalid position. Cannot delete element.\n");
        return;
    }
    for (int i = position; i < *size - 1; i++)
        arr[i] = arr[i + 1];
    (*size)--;
    printf("Element deleted successfully.\n");
}

int main() {
    int arr[MAX_SIZE], size = 1, choice, position, element;

    do {
        printf("\nLinear Array Operations\n1. Display the array\n2. Insert an element\n3. Delete an element\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayArray(arr, size);
                break;
            case 2:
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insertElement(arr, &size, position, element);
                break;
            case 3:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteElement(arr, &size, position);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    return 0;
}