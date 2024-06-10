#include <stdio.h>

#define SIZE 10

int queue[SIZE];
int FRONT = 0, REAR = -1;

void enqueue(int a)
{
    if (REAR == SIZE - 1)
    {
        printf("Overflow\n");
    }
    else
    {
        REAR = REAR + 1;
        queue[REAR] = a;
    }
}

void dequeue()
{
    if (FRONT > REAR)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("-> %d\n", queue[FRONT]);
        FRONT = FRONT + 1;
    }
}

void display()
{
    for (int i = FRONT; i <= REAR; i++)
    {
        printf("%d, ", queue[i]);
    }
    printf("\n");
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    enqueue(11);
    dequeue();
    dequeue();
    return 0;
}
