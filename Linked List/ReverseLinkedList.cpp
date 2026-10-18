
/*
 * Description:
 * Reverses a Singly Linked List by changing
 * the direction of its pointers.
 *
 * Key Concepts:
 * 1. Three-Pointer Technique
 * 2. Pointer Reassignment
 * 3. Iterative Reversal
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

// Display the linked list.
void displayList(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }

    cout << "NULL\n";
}

// Reverse the linked list.
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* nextNode = nullptr;

    while (current != nullptr) {
        // Save the next node before changing the link.
        nextNode = current->next;

        // Reverse the current node's pointer.
        current->next = prev;

        // Move prev and current one step forward.
        prev = current;
        current = nextNode;
    }

    // The previous node becomes the new head.
    return prev;
}

int main() {
    // Create the linked list: 10 -> 20 -> 30 -> 40.
    Node* head = createNode(10);

    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    cout << "===== REVERSE LINKED LIST =====\n\n";

    cout << "Original List: ";
    displayList(head);

    // Reverse the linked list.
    head = reverseList(head);

    cout << "Reversed List: ";
    displayList(head);

    // Free the allocated memory.
    Node* current = head;

    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    head = nullptr;

    return 0;
}
