
/*
 * Key Concepts:
 * 1. Node Creation
 * 2. Previous and Next Pointers
 * 3. Forward Traversal
 * 4. Backward Traversal
 */

#include <iostream>
using namespace std;

// Define the structure of a doubly linked list node.
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Create a new node.
Node* createNode(int value) {
    Node* newNode = new Node;

    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    return newNode;
}

// Display the list from first node to last node.
void displayForward(Node* head) {
    Node* current = head;

    cout << "Forward: ";

    while (current != nullptr) {
        cout << current->data << " <-> ";
        current = current->next;
    }

    cout << "NULL\n";
}

// Display the list from last node to first node.
void displayBackward(Node* tail) {
    Node* current = tail;

    cout << "Backward: ";

    while (current != nullptr) {
        cout << current->data << " <-> ";
        current = current->prev;
    }

    cout << "NULL\n";
}

int main() {
    // Create three nodes.
    Node* first = createNode(10);
    Node* second = createNode(20);
    Node* third = createNode(30);

    // Connect the first and second nodes.
    first->next = second;
    second->prev = first;

    // Connect the second and third nodes.
    second->next = third;
    third->prev = second;

    // Set the head and tail pointers.
    Node* head = first;
    Node* tail = third;

    cout << "===== DOUBLY LINKED LIST =====\n\n";

    displayForward(head);
    displayBackward(tail);

    // Free the allocated memory.
    Node* current = head;

    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    head = nullptr;
    tail = nullptr;

    return 0;
}
