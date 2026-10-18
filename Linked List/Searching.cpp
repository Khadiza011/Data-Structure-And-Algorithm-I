
/*
 * Description:
 * Searches for a given value in a Singly Linked List
 * using the Linear Search technique.
 *
 * Key Concepts:
 * 1. Linear Search
 * 2. Pointer Traversal
 * 3. Finding an Element's Position
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

// Search for a value and return its position.
// Positions start from 1.
int searchElement(Node* head, int target) {
    Node* current = head;
    int position = 1;

    while (current != nullptr) {
        // Check whether the current node contains the target.
        if (current->data == target) {
            return position;
        }

        // Move to the next node.
        current = current->next;
        position++;
    }

    // Return -1 if the target is not found.
    return -1;
}

// Display the linked list.
void displayList(Node* head) {
    Node* current = head;

    cout << "Linked List: ";

    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }

    cout << "NULL\n";
}

// Free all allocated memory.
void freeList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Create the linked list: 10 -> 20 -> 30 -> 40 -> 50.
    Node* head = createNode(10);

    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);

    cout << "===== LINKED LIST SEARCHING =====\n\n";

    displayList(head);

    // Search for an existing value.
    int target = 30;
    int position = searchElement(head, target);

    if (position != -1) {
        cout << target << " found at position "
             << position << ".\n";
    } else {
        cout << target << " not found in the list.\n";
    }

    // Search for a value that does not exist.
    target = 60;
    position = searchElement(head, target);

    if (position != -1) {
        cout << target << " found at position "
             << position << ".\n";
    } else {
        cout << target << " not found in the list.\n";
    }

    // Free allocated memory.
    freeList(head);
    head = nullptr;

    return 0;
}
