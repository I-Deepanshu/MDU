#include <stdio.h>
#include <stdlib.h>

// Structure for queue node
struct Node
{
    int data;
    struct Node *next;
};

// Structure for queue
struct Queue
{
    struct Node *front;
    struct Node *rear;
};

// Function to initialize the queue
void initQueue(struct Queue *queue)
{
    queue->front = NULL;
    queue->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue)
{
    return (queue->front == NULL);
}

// Function to enqueue an element to the rear of the queue
void enqueue(struct Queue *queue, int data)
{
    // Create a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // If the queue is empty, set both front and rear to the new node
    if (isEmpty(queue))
    {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        // Otherwise, add the new node to the rear and update the rear pointer
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue an element from the front of the queue
int dequeue(struct Queue *queue)
{
    // If the queue is empty, return -1
    if (isEmpty(queue))
    {
        return -1;
    }

    // Store the front node and its data
    struct Node *temp = queue->front;
    int data = temp->data;

    // Move the front pointer to the next node
    queue->front = queue->front->next;

    // If the front becomes NULL, update the rear pointer to NULL as well
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }

    // Free the memory of the dequeued node
    free(temp);

    // Return the dequeued data
    return data;
}

// Function to get the front element of the queue without removing it
int front(struct Queue *queue)
{
    // If the queue is empty, return -1
    if (isEmpty(queue))
    {
        return -1;
    }

    // Return the data of the front node
    return queue->front->data;
}

// Function to display the elements of the queue
void display(struct Queue *queue)
{
    // If the queue is empty, print a message
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return;
    }

    // Traverse the queue and print the data of each node
    struct Node *temp = queue->front;
    printf("Queue elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Queue queue;
    initQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    display(&queue);

    printf("Front element: %d\n", front(&queue));

    printf("Dequeued element: %d\n", dequeue(&queue));

    display(&queue);

    return 0;
}
