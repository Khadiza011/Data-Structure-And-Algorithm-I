
/*
 * Description:
 * Demonstrates how to visit each node of a
 * Singly Linked List using a pointer.
 *
 * Operations:
 * 1. Display all elements
 * 2. Count total nodes
 * 3. Search for an element
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

// Display every node from beginning to end.
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

// Count the total number of nodes.
int countNodes(Node* head) {
    int count = 0;
    Node* current = head;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}

// Search for a value in the linked list.
bool searchElement(Node* head, int target) {
    Node* current = head;

    while (current != nullptr) {
        if (current->data == target) {
            return true;
        }

        current = current->next;
    }

    return false;
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
    // Create a linked list: 10 -> 20 -> 30 -> 40.
    Node* head = createNode(10);

    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    cout << "===== LINKED LIST TRAVERSAL =====\n\n";

    // Display all elements.
    displayList(head);

    // Count the total nodes.
    cout << "Total Nodes: " << countNodes(head) << '\n';

    // Search for an existing element.
    int target = 30;

    if (searchElement(head, target)) {
        cout << target << " was found in the list.\n";
    } else {
        cout << target << " was not found in the list.\n";
    }

    // Search for a missing element.
    target = 50;

    if (searchElement(head, target)) {
        cout << target << " was found in the list.\n";
    } else {
        cout << target << " was not found in the list.\n";
    }

    // Free allocated memory.
    freeList(head);
    head = nullptr;

    return 0;
}
