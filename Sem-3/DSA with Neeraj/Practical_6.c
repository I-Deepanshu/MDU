/*
Program to implement Stack and Queue
Author: Neeraj
Date: October 30, 2023
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int stack[MAX], queue[MAX];
int top = -1, front = -1, rear = -1;

void push(int);
int pop();
void enqueue(int);
int dequeue();
void display();

int main()
{
    int choice, item;
    while(1)
    {
        printf("\n\n1. Push\n2. Pop\n3. Enqueue\n4. Dequeue\n5. Display\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the element to be pushed: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                item = pop();
                if(item == -1)
                    printf("\nStack is empty");
                else
                    printf("\nThe popped element is %d", item);
                break;
            case 3:
                printf("\nEnter the element to be enqueued: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 4:
                item = dequeue();
                if(item == -1)
                    printf("\nQueue is empty");
                else
                    printf("\nThe dequeued element is %d", item);
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid choice");
        }
    }
    return 0;
}

void push(int item)
{
    if(top == MAX - 1)
        printf("\nStack overflow");
    else
    {
        top++;
        stack[top] = item;
    }
}

int pop()
{
    int item;
    if(top == -1)
        return -1;
    else
    {
        item = stack[top];
        top--;
        return item;
    }
}

void enqueue(int item)
{
    if(rear == MAX - 1)
        printf("\nQueue overflow");
    else
    {
        if(front == -1)
            front = 0;
        rear++;
        queue[rear] = item;
    }
}

int dequeue()
{
    int item;
    if(front == -1 || front > rear)
        return -1;
    else
    {
        item = queue[front];
        front++;
        return item;
    }
}

void display()
{
    int i;
    if(top == -1)
        printf("\nStack is empty");
    else
    {
        printf("\nThe elements of the stack are: ");
        for(i = top; i >= 0; i--)
            printf("%d ", stack[i]);
    }
    if(front == -1 || front > rear)
        printf("\nQueue is empty");
    else
    {
        printf("\nThe elements of the queue are: ");
        for(i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }
}