
/*
 * A Stack follows the LIFO principle:
 * Last In, First Out.
 *
 * This program implements a Stack using a
 * Singly Linked List.
 */

#include <iostream>
using namespace std;

// Define the structure of a node.
struct Node {
    int data;
    Node* next;
};

// Top points to the top node of the stack.
Node* top = nullptr;

// Check whether the stack is empty.
bool isEmpty() {
    return top == nullptr;
}

// Insert an element at the top of the stack.
void push(int value) {
    // Create a new node.
    Node* newNode = new Node;

    newNode->data = value;

    // Connect the new node to the current top.
    newNode->next = top;

    // Make the new node the top node.
    top = newNode;

    cout << value << " pushed into the stack.\n";
}

// Remove the top element.
void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow! Stack is empty.\n";
        return;
    }

    // Keep the address of the top node.
    Node* temp = top;

    cout << temp->data << " popped from the stack.\n";

    // Move top to the next node.
    top = top->next;

    // Free the removed node's memory.
    delete temp;
}

// Display the top element without removing it.
void peek() {
    if (isEmpty()) {
        cout << "Stack is empty!\n";
        return;
    }

    cout << "Top element: " << top->data << '\n';
}

// Display all elements from top to bottom.
void displayStack() {
    if (isEmpty()) {
        cout << "Stack is empty!\n";
        return;
    }

    Node* current = top;

    cout << "Stack (Top to Bottom): ";

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    cout << '\n';
}

// Remove all remaining nodes from memory.
void clearStack() {
    while (top != nullptr) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

int main() {
    cout << "===== STACK USING LINKED LIST =====\n\n";

    // Insert elements into the stack.
    push(10);
    push(20);
    push(30);

    cout << '\n';
    displayStack();

    // View the top element.
    peek();

    cout << '\n';

    // Remove the top element.
    pop();

    cout << '\n';
    displayStack();
    peek();

    // Free the remaining memory.
    clearStack();

    return 0;
}
