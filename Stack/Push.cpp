
/*
 * Push inserts a new element at the top of a Stack.
 * This program uses an array to implement the Stack.
 */

#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

int stackArray[MAX_SIZE];
int top = -1;

// Insert a new element at the top of the Stack.
void push(int value) {
    // Check whether the Stack is full.
    if (top == MAX_SIZE - 1) {
        cout << "Stack Overflow! Cannot push "
             << value << ".\n";
        return;
    }

    // Move top to the next position.
    top++;

    // Store the new element.
    stackArray[top] = value;

    cout << value << " pushed successfully.\n";
}

// Display the Stack from top to bottom.
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
    cout << "===== PUSH OPERATION =====\n\n";

    cout << "Initial Stack:\n";
    displayStack();

    cout << "\nPushing elements:\n";

    push(10);
    push(20);
    push(30);

    cout << '\n';
    displayStack();

    cout << "\nPushing more elements:\n";

    push(40);
    push(50);
    push(60);  // Stack is full.

    cout << '\n';
    displayStack();

    return 0;
}
