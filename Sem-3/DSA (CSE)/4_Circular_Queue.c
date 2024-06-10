#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value)
{
    if ((rear + 1) % SIZE == front)
    {
        printf("Queue is full.\n");
    }
    else
    {
        rear = (rear + 1) % SIZE;
        queue[rear] = value;
        if (front == -1)
        {
            front = 0;
        }
        printf("%d Enqueued\n", value);
    }
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        int value = queue[front];
        printf("Dequeued %d\n", value);
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
    }
}

int isFull()
{
    return (rear + 1) % SIZE == front;
}

int isEmpty()
{
    return front == -1;
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("> ");
        int i = front;
        while (i != rear)
        {
            printf("%d ", queue[i]);
            i = (i + 1) % SIZE;
        }
        printf("%d\n", queue[rear]);
    }
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6); // Queue is full.

    display(); // Queue: 1 2 3 4 5

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue(); // Queue is empty.

    display(); // Queue is empty.

    return 0;
}

