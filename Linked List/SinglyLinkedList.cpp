
/*
 * Key Concepts:
 * 1. Node Creation
 * 2. Data and Next Pointer
 * 3. Linking Nodes
 * 4. Traversal
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

// Display all elements of the linked list.
void displayList(Node* head) {
    if (head == nullptr) {
        cout << "Linked List is empty!\n";
        return;
    }

    Node* current = head;

    cout << "Linked List: ";

    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }

    cout << "NULL\n";
}

int main() {
    // Create three nodes.
    Node* first = createNode(10);
    Node* second = createNode(20);
    Node* third = createNode(30);

    // Link the nodes together.
    first->next = second;
    second->next = third;

    // The first node is the head of the list.
    Node* head = first;

    cout << "===== SINGLY LINKED LIST =====\n\n";

    displayList(head);

    // Display the first element.
    cout << "First Element: " << head->data << '\n';

    // Display the last element.
    Node* current = head;

    while (current->next != nullptr) {
        current = current->next;
    }

    cout << "Last Element: " << current->data << '\n';

    // Free the allocated memory.
    current = head;

    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    head = nullptr;

    return 0;
}
