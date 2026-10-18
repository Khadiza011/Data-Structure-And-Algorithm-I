
/*
 * Description:
 * Demonstrates how to insert elements at the rear
 * of a Queue using a normal array.
 *
 * Key Concepts:
 * 1. Enqueue
 * 2. Front and Rear
 * 3. Queue Overflow
 */

#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

int queueArray[MAX_SIZE];
int front = -1;
int rear = -1;

// Insert an element at the rear of the queue.
void enqueue(int value) {
    // Check whether the queue is full.
    if (rear == MAX_SIZE - 1) {
        cout << "Queue Overflow! Cannot insert "
             << value << ".\n";
        return;
    }

    // Initialize front when inserting the first element.
    if (front == -1) {
        front = 0;
    }

    // Insert the new element at the rear.
    rear++;
    queueArray[rear] = value;

    cout << value << " inserted successfully.\n";
}

// Display all elements in the queue.
void displayQueue() {
    if (front == -1) {
        cout << "Queue is empty!\n";
        return;
    }

    cout << "Queue: ";

    for (int i = front; i <= rear; i++) {
        cout << queueArray[i] << " ";
    }

    cout << '\n';
}

int main() {
    cout << "========== ENQUEUE OPERATION ==========\n\n";

    enqueue(10);
    enqueue(20);
    enqueue(30);

    cout << '\n';
    displayQueue();

    cout << "\nInserting more elements:\n";

    enqueue(40);
    enqueue(50);
    enqueue(60);  // Queue is full.

    cout << '\n';
    displayQueue();

    return 0;
}
