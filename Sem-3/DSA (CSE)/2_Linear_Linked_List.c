#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new element into the linked list in ascending order
void insertElement(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL || data < (*head)->data)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        struct Node *current = *head;
        while (current->next != NULL && current->next->data < data)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to delete an element from the linked list
void deleteElement(struct Node **head, int data)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *current = *head;
    struct Node *prev = NULL;
    while (current != NULL && current->data != data)
    {
        prev = current;
        current = current->next;
    }
    if (current == NULL)
    {
        printf("Element not found in the list.\n");
        return;
    }
    if (prev == NULL)
    {
        *head = current->next;
    }
    else
    {
        prev->next = current->next;
    }
    free(current);
    printf("Element deleted successfully.\n");
}

// Function to display the elements of the linked list
void displayList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *current = head;
    printf("List elements: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;
    int choice, data;

    while (1)
    {
        printf("Menu:\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("> Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &data);
            insertElement(&head, data);
            break;
        case 2:
            printf("Enter the element to delete: ");
            scanf("%d", &data);
            deleteElement(&head, data);
            break;
        case 3:
            displayList(head);
            break;
        case 4:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}