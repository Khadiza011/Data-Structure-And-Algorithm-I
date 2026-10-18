
/*
 * Description:
 * Implements a Queue using a Singly Linked List.
 *
 * Key Concepts:
 * 1. FIFO Principle
 * 2. Front and Rear Pointers
 * 3. Enqueue
 * 4. Dequeue
 * 5. Dynamic Memory Allocation
 */

#include <iostream>
using namespace std;

// Define the structure of a node.
struct Node {
    int data;
    Node* next;
};

// Front points to the first node.
// Rear points to the last node.
Node* front = nullptr;
Node* rear = nullptr;

// Check whether the queue is empty.
bool isEmpty() {
    return front == nullptr;
}

// Insert an element at the rear of the queue.
void enqueue(int value) {
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = nullptr;

    // If the queue is empty, both pointers
    // must point to the new node.
    if (isEmpty()) {
        front = newNode;
        rear = newNode;
    } else {
        // Connect the new node after the last node.
        rear->next = newNode;
        rear = newNode;
    }

    cout << value << " inserted into the queue.\n";
}

// Remove an element from the front of the queue.
void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty! Cannot remove an element.\n";
        return;
    }

    Node* temp = front;

    cout << temp->data << " removed from the queue.\n";

    // Move front to the next node.
    front = front->next;

    // If the queue becomes empty, reset rear too.
    if (front == nullptr) {
        rear = nullptr;
    }

    delete temp;
}

// Display all elements in the queue.
void displayQueue() {
    if (isEmpty()) {
        cout << "Queue is empty!\n";
        return;
    }

    Node* current = front;

    cout << "Queue: ";

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    cout << '\n';
}

// Return the number of elements in the queue.
int countElements() {
    int count = 0;
    Node* current = front;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}

int main() {
    cout << "===== QUEUE USING LINKED LIST =====\n\n";

    // Insert elements into the queue.
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    cout << '\n';
    displayQueue();

    cout << "Total elements: " << countElements() << '\n';

    // Remove the first element.
    cout << '\n';
    dequeue();

    displayQueue();

    cout << "Total elements: " << countElements() << '\n';

    // Remove the remaining elements.
    cout << '\n';
    dequeue();
    dequeue();
    dequeue();

    displayQueue();

    return 0;
}
