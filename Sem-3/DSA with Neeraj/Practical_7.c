#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
}*start = NULL;

void insert(int item, int position) {
    struct node *new_node, *ptr, *preptr;
    int i;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = item;
    if(position == 1) {
        new_node->next = start;
        start = new_node;
    } else {
        ptr = start;
        for(i = 1; i < position; i++) {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = new_node;
        new_node->next = ptr;
    }
}

void delete(int position) {
    struct node *ptr, *preptr;
    int i;
    if(start == NULL)
        printf("\nList is empty");
    else if(position == 1) {
        ptr = start;
        start = start->next;
        free(ptr);
    } else {
        ptr = start;
        for(i = 1; i < position; i++) {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
    }
}

void display() {
    struct node *ptr;
    if(start == NULL)
        printf("\nList is empty");
    else {
        ptr = start;
        while(ptr != NULL) {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
    }
}

int main() {
    int choice, item, position;
    while(1) {
        printf("\n\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter the element to be inserted: ");
                scanf("%d", &item);
                printf("\nEnter the position: ");
                scanf("%d", &position);
                insert(item, position);
                break;
            case 2:
                printf("\nEnter the position: ");
                scanf("%d", &position);
                delete(position);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice");
        }
    }
    return 0;
}