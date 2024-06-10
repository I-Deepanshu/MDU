#include <iostream>
using namespace std;

// Define the Node struct
struct Node {
    int data;
    Node* next;
    
    // Constructor
    Node(int val) : data(val), next(nullptr) {}
};

Node* InsertNode(Node* head, int pos, Node* newNode) {
    // Base case: if the position is 0, insert at the beginning
    if (pos == 0) {
        newNode->next = head;
        return newNode;
    }

    // Base case: if the head is null, return null (invalid position)
    if (head == nullptr) {
        cout << "Invalid position. The linked list is not long enough." << endl;
        return nullptr;
    }

    // Recursive case: move to the next node and decrement the position
    head->next = InsertNode(head->next, pos - 1, newNode);
    return head;
}

// Function to print the linked list
void PrintList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example usage
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    cout << "Original linked list: ";
    PrintList(head);

    Node* newNode = new Node(4);
    head = InsertNode(head, 2, newNode);

    cout << "Linked list after insertion: ";
    PrintList(head);

    return 0;
}


/*
Approach:

Base Case:
    1. If the linked list is empty (head == nullptr) or the position is 0, it means the new node should be inserted at the beginning.
    2. In such cases, the newNode is connected to the current head, and the function returns the newNode as the new head of the linked list.

Recursive Case:
    1. If the base case is not satisfied, the function moves to the next node in the linked list (head->next) and decrements the position (pos - 1).
    2. The recursive call is made to insert the newNode at the specified position in the remaining part of the linked list.
    3. The modified head is then returned.
    4. The recursion continues until the base case is met, and the new node is appropriately inserted at the specified position in the linked list.
*/