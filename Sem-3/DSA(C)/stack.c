#include <stdio.h>
#define size 10

void push(int stack[], int *TOP, int a);
void pop(int stack[], int *TOP);
void display(int stack[], int *TOP);

int main()
{
    int stack[size];
    int pointer = -1;
    int *TOP = &pointer;

    push(stack, TOP, 10);
    push(stack, TOP, 20);
    push(stack, TOP, 30);
    display(stack, TOP);
    pop(stack, TOP);
    display(stack, TOP);

    return 0;
}

void push(int stack[], int *TOP, int a)
{
    if (*TOP == size - 1)
    {
        printf("Overflow\n");
    }
    else
    {
        *TOP = *TOP + 1;
        stack[*TOP] = a;
    }
}

void pop(int stack[], int *TOP)
{
    if (*TOP == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("-> %d\n", stack[*TOP]);
        *TOP = *TOP - 1;
    }
}

void display(int stack[], int *TOP)
{
    for (int i = *TOP; i >= 0; i--)
    {
        printf("%d |", stack[i]);
    }
}