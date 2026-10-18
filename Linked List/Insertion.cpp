
/*
 * Description:
 * Demonstrates insertion at the beginning, end,
 * and a specific position in a Singly Linked List.
 *
 * Operations:
 * 1. Insert at Beginning
 * 2. Insert at End
 * 3. Insert at a Specific Position
 * 4. Display the Linked List
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

// Insert a node at the beginning.
Node* insertAtBeginning(Node* head, int value) {
    Node* newNode = createNode(value);

    newNode->next = head;
    head = newNode;

    cout << value << " inserted at the beginning.\n";

    return head;
}

// Insert a node at the end.
Node* insertAtEnd(Node* head, int value) {
    Node* newNode = createNode(value);

    // If the list is empty, the new node becomes the head.
    if (head == nullptr) {
        cout << value << " inserted at the end.\n";
        return newNode;
    }

    Node* current = head;

    // Find the last node.
    while (current->next != nullptr) {
        current = current->next;
    }

    // Connect the last node to the new node.
    current->next = newNode;

    cout << value << " inserted at the end.\n";

    return head;
}

// Insert a node at a specific position (1-based).
Node* insertAtPosition(Node* head, int value, int position) {
    if (position < 1) {
        cout << "Invalid position!\n";
        return head;
    }

    // Position 1 means insertion at the beginning.
    if (position == 1) {
        return insertAtBeginning(head, value);
    }

    Node* current = head;

    // Move to the node immediately before the target position.
    for (int i = 1; i < position - 1 && current != nullptr; i++) {
        current = current->next;
    }

    // The requested position does not exist.
    if (current == nullptr) {
        cout << "Invalid position!\n";
        return head;
    }

    Node* newNode = createNode(value);

    // Connect the new node to the next node.
    newNode->next = current->next;

    // Connect the previous node to the new node.
    current->next = newNode;

    cout << value << " inserted at position "
         << position << ".\n";

    return head;
}

// Free all dynamically allocated nodes.
void freeList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;

    cout << "===== LINKED LIST INSERTION =====\n\n";

    // Insert elements at the beginning.
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 10);

    displayList(head);

    cout << '\n';

    // Insert an element at the end.
    head = insertAtEnd(head, 40);

    displayList(head);

    cout << '\n';

    // Insert an element at position 3.
    head = insertAtPosition(head, 30, 3);

    displayList(head);

    // Free allocated memory.
    freeList(head);
    head = nullptr;

    return 0;
}
