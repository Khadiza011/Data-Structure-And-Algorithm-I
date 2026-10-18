
/*
 * Description:
 * Demonstrates how to remove elements from the
 * front of a Queue using a normal array.
 *
 * Key Concepts:
 * 1. Dequeue
 * 2. Front and Rear
 * 3. Queue Underflow
 * 4. Empty Queue Handling
 */

#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

int queueArray[MAX_SIZE];
int front = -1;
int rear = -1;

// Remove an element from the front of the queue.
void dequeue() {
    // Check whether the queue is empty.
    if (front == -1) {
        cout << "Queue Underflow! Cannot remove an element.\n";
        return;
    }

    // Display the element being removed.
    cout << queueArray[front]
         << " removed from the queue.\n";

    // Reset the queue if this is the last element.
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        // Move front to the next position.
        front++;
    }
}

// Insert an element to demonstrate dequeue.
void enqueue(int value) {
    if (rear == MAX_SIZE - 1) {
        cout << "Queue Overflow!\n";
        return;
    }

    if (front == -1) {
        front = 0;
    }

    rear++;
    queueArray[rear] = value;
}

// Display the current queue.
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
    cout << "========== DEQUEUE OPERATION ==========\n\n";

    // Insert sample elements.
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    cout << "Initial ";
    displayQueue();

    cout << '\n';

    // Remove elements from the front.
    dequeue();
    displayQueue();

    cout << '\n';

    dequeue();
    displayQueue();

    cout << '\n';

    dequeue();
    dequeue();

    displayQueue();

    // Attempt to remove from an empty queue.
    cout << '\n';
    dequeue();

    return 0;
}
