
/*
 * Key Concepts:
 * 1. Circular Structure
 * 2. Node Creation
 * 3. Linking Nodes
 * 4. Circular Traversal
 */

#include <iostream>
using namespace std;

// Define the structure of a node.
struct Node {
    int data;
    Node* next;
};

// Create a new node.
Node* createNode(int value) {
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = nullptr;

    return newNode;
}

// Display all nodes exactly once.
void displayList(Node* head) {
    if (head == nullptr) {
        cout << "Circular Linked List is empty!\n";
        return;
    }

    Node* current = head;

    cout << "Circular Linked List: ";

    do {
        cout << current->data << " -> ";
        current = current->next;
    } while (current != head);

    cout << "HEAD\n";
}

int main() {
    // Create three nodes.
    Node* first = createNode(10);
    Node* second = createNode(20);
    Node* third = createNode(30);

    // Connect the nodes.
    first->next = second;
    second->next = third;

    // Connect the last node back to the first node.
    third->next = first;

    Node* head = first;

    cout << "===== CIRCULAR LINKED LIST =====\n\n";

    displayList(head);

    // Display the first node.
    cout << "First Element: " << head->data << '\n';

    // Free each node exactly once.
    second->next = nullptr;

    Node* current = head;

    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    head = nullptr;

    return 0;
}
