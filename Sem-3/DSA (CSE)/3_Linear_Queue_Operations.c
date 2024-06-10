#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int element)
{
    if (rear == MAX_SIZE - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        rear++;
        queue[rear] = element;
        printf("Element %d enqueued successfully\n", element);
    }
}

void dequeue()
{
    if (front == rear)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        front++;
        printf("Element %d dequeued successfully\n", queue[front]);
    }
}

void display()
{
    if (front == rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Elements in the queue: ");
        for (int i = front + 1; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int peek()
{
    if (front == rear)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    else
    {
        return queue[front + 1];
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    int frontElement = peek();
    printf("Front element: %d\n", frontElement);
    return 0;
}