
/*
 * Description:
 * Demonstrates deletion at the beginning, end,
 * and a specific position in a Singly Linked List.
 *
 * Operations:
 * 1. Delete from Beginning
 * 2. Delete from End
 * 3. Delete from a Specific Position
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

// Delete the first node.
Node* deleteFromBeginning(Node* head) {
    if (head == nullptr) {
        cout << "Cannot delete! List is empty.\n";
        return head;
    }

    Node* temp = head;

    cout << "Deleted element: " << temp->data << '\n';

    head = head->next;

    delete temp;

    return head;
}

// Delete the last node.
Node* deleteFromEnd(Node* head) {
    if (head == nullptr) {
        cout << "Cannot delete! List is empty.\n";
        return head;
    }

    // If there is only one node.
    if (head->next == nullptr) {
        cout << "Deleted element: " << head->data << '\n';

        delete head;
        return nullptr;
    }

    Node* current = head;

    // Find the second-last node.
    while (current->next->next != nullptr) {
        current = current->next;
    }

    Node* temp = current->next;

    cout << "Deleted element: " << temp->data << '\n';

    current->next = nullptr;

    delete temp;

    return head;
}

// Delete a node at a specific position (1-based).
Node* deleteAtPosition(Node* head, int position) {
    if (position < 1 || head == nullptr) {
        cout << "Invalid position or empty list!\n";
        return head;
    }

    // Position 1 means deleting the first node.
    if (position == 1) {
        return deleteFromBeginning(head);
    }

    Node* current = head;

    // Move to the node before the target position.
    for (int i = 1; i < position - 1 && current != nullptr; i++) {
        current = current->next;
    }

    // Check whether the requested position exists.
    if (current == nullptr || current->next == nullptr) {
        cout << "Invalid position!\n";
        return head;
    }

    Node* temp = current->next;

    cout << "Deleted element: " << temp->data << '\n';

    // Skip the node being deleted.
    current->next = temp->next;

    delete temp;

    return head;
}

// Free all remaining nodes.
void freeList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;

    // Create the initial list: 10 -> 20 -> 30 -> 40.
    head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    cout << "===== LINKED LIST DELETION =====\n\n";

    cout << "Initial ";
    displayList(head);

    cout << '\n';

    // Delete the first node.
    head = deleteFromBeginning(head);
    displayList(head);

    cout << '\n';

    // Delete the last node.
    head = deleteFromEnd(head);
    displayList(head);

    cout << '\n';

    // Delete the node at position 2.
    head = deleteAtPosition(head, 2);
    displayList(head);

    // Free remaining memory.
    freeList(head);
    head = nullptr;

    return 0;
}
