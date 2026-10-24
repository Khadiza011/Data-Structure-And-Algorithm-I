
/*
 * Topic: Peek Operation
 * File: Peek.cpp
 *
 * Peek displays the top element of a Stack
 * without removing it.
 *
 * This program uses an array to implement the Stack.
 */

#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

int stackArray[MAX_SIZE];
int top = -1;

// Insert an element into the Stack.
void push(int value) {
    if (top == MAX_SIZE - 1) {
        cout << "Stack Overflow!\n";
        return;
    }

    top++;
    stackArray[top] = value;
}

// Display the top element without removing it.
void peek() {
    // Check whether the Stack is empty.
    if (top == -1) {
        cout << "Stack is empty! No top element.\n";
        return;
    }

    cout << "Top element: " << stackArray[top] << '\n';
}

// Display all elements from top to bottom.
void displayStack() {
    if (top == -1) {
        cout << "Stack is empty!\n";
        return;
    }

    cout << "Stack (Top to Bottom): ";

    for (int i = top; i >= 0; i--) {
        cout << stackArray[i] << " ";
    }

    cout << '\n';
}

int main() {
    cout << "===== PEEK OPERATION =====\n\n";

    // Try peek on an empty Stack.
    cout << "Checking an empty Stack:\n";
    peek();

    cout << "\nPushing elements:\n";

    push(10);
    push(20);
    push(30);

    displayStack();

    cout << "\nPeeking at the top element:\n";
    peek();

    // Check the Stack again to show that nothing was removed.
    cout << "\nStack after peek:\n";
    displayStack();

    return 0;
}
