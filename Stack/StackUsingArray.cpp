
/*
 * A Stack follows the LIFO principle:
 * Last In, First Out.
 *
 * The last inserted element is removed first.
 */

#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

int stackArray[MAX_SIZE];
int top = -1;

// Check whether the stack is empty.
bool isEmpty() {
    return top == -1;
}

// Check whether the stack is full.
bool isFull() {
    return top == MAX_SIZE - 1;
}

// Insert an element at the top of the stack.
void push(int value) {
    if (isFull()) {
        cout << "Stack Overflow! Cannot insert "
             << value << ".\n";
        return;
    }

    top++;
    stackArray[top] = value;

    cout << value << " pushed into the stack.\n";
}

// Remove the top element.
void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow! Stack is empty.\n";
        return;
    }

    cout << stackArray[top] << " popped from the stack.\n";

    top--;
}

// Show the top element without removing it.
void peek() {
    if (isEmpty()) {
        cout << "Stack is empty!\n";
        return;
    }

    cout << "Top element: " << stackArray[top] << '\n';
}

// Display elements from top to bottom.
void displayStack() {
    if (isEmpty()) {
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
    cout << "===== STACK USING ARRAY =====\n\n";

    // Insert elements.
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

    return 0;
}
