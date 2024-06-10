#include <iostream>
using namespace std;

// Node structure for both stack and queue
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Stack implementation
class Stack {
private:
    Node* top;
public:
    Stack() : top(nullptr) {}

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop.\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. No top element.\n";
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

// Queue implementation
class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. No front element.\n";
            return -1;
        }
        return front->data;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    // Stack operations
    Stack myStack;
    cout << "Stack operations:\n";
    myStack.push(10);
    cout << "Pushed 10 onto the stack.\n";
    myStack.push(20);
    cout << "Pushed 20 onto the stack.\n";
    myStack.push(30);
    cout << "Pushed 30 onto the stack.\n";

    cout << "Top element of the stack: " << myStack.peek() << endl;
    cout << "Popping elements from the stack:\n";
    while (!myStack.isEmpty()) {
        cout << "Popped: " << myStack.peek() << endl;
        myStack.pop();
    }
    cout << endl;

    // Queue operations
    Queue myQueue;
    cout << "Queue operations:\n";
    myQueue.enqueue(10);
    cout << "Enqueued 10 into the queue.\n";
    myQueue.enqueue(20);
    cout << "Enqueued 20 into the queue.\n";
    myQueue.enqueue(30);
    cout << "Enqueued 30 into the queue.\n";

    cout << "Front element of the queue: " << myQueue.peek() << endl;
    cout << "Dequeueing elements from the queue:\n";
    while (!myQueue.isEmpty()) {
        cout << "Dequeued: " << myQueue.peek() << endl;
        myQueue.dequeue();
    }
    cout << endl;

    return 0;
}

PS E:\GitHub\MDU\Sem-4\DAA> cd "e:\GitHub\MDU\Sem-4\DAA\" ; if ($?) { g++ 2_stack_queue.cpp -o 2_stack_queue } ; if ($?) { .\2_stack_queue }
Stack operations:
Pushed 10 onto the stack.
Pushed 20 onto the stack.
Pushed 30 onto the stack.
Top element of the stack: 30
Popping elements from the stack:
Popped: 30
Popped: 20
Popped: 10

Queue operations:
Enqueued 10 into the queue.
Enqueued 20 into the queue.
Enqueued 30 into the queue.
Front element of the queue: 10
Dequeueing elements from the queue:
Dequeued: 10
Dequeued: 20
Dequeued: 30