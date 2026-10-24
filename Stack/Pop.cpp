
/*
 * Pop removes the top element from a Stack.
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

// Remove the top element from the Stack.
void pop() {
    // Check whether the Stack is empty.
    if (top == -1) {
        cout << "Stack Underflow! Stack is empty.\n";
        return;
    }

    // Display the element being removed.
    cout << stackArray[top] << " popped from the Stack.\n";

    // Move top one position down.
    top--;
}

// Display elements from top to bottom.
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
    cout << "===== POP OPERATION =====\n\n";

    // Insert some elements.
    push(10);
    push(20);
    push(30);
    push(40);

    cout << "Initial ";
    displayStack();

    cout << "\nRemoving elements:\n";

    pop();
    displayStack();

    cout << '\n';

    pop();
    displayStack();

    cout << '\n';

    pop();
    pop();

    displayStack();

    // Try to remove an element from an empty Stack.
    cout << '\n';
    pop();

    return 0;
}
