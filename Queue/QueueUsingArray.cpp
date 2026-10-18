
/*
 * Description:
 * Implements a simple Queue using a normal array.
 *
 * Key Concepts:
 * 1. FIFO Principle
 * 2. Front and Rear
 * 3. Enqueue
 * 4. Dequeue
 * 5. Display Queue
 */

#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

int queueArray[MAX_SIZE];
int front = -1;
int rear = -1;

// Check whether the queue is empty.
bool isEmpty() {
    return front == -1;
}

// Check whether the queue is full.
bool isFull() {
    return rear == MAX_SIZE - 1;
}

// Insert an element at the rear.
void enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full! Cannot insert "
             << value << ".\n";
        return;
    }

    // Set front when inserting the first element.
    if (isEmpty()) {
        front = 0;
    }

    rear++;
    queueArray[rear] = value;

    cout << value << " inserted into the queue.\n";
}

// Remove an element from the front.
void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty! Cannot remove an element.\n";
        return;
    }

    cout << queueArray[front]
         << " removed from the queue.\n";

    // If this was the last element, reset the queue.
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front++;
    }
}

// Display all elements in the queue.
void displayQueue() {
    if (isEmpty()) {
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
    cout << "========== QUEUE USING ARRAY ==========\n\n";

    // Insert elements into the queue.
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    cout << '\n';
    displayQueue();

    // Remove the first element.
    cout << '\n';
    dequeue();

    displayQueue();

    // Insert another element.
    cout << '\n';
    enqueue(50);

    displayQueue();

    return 0;
}
