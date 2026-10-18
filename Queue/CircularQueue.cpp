
/*
 * Description:
 * Implements a Circular Queue using a normal array.
 * Empty spaces are reused through circular indexing.
 *
 * Key Concepts:
 * 1. FIFO Principle
 * 2. Circular Indexing
 * 3. Enqueue and Dequeue
 * 4. Front and Rear
 * 5. Overflow and Underflow
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
    return (rear + 1) % MAX_SIZE == front;
}

// Insert an element into the circular queue.
void enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full! Cannot insert "
             << value << ".\n";
        return;
    }

    // Initialize front when inserting the first element.
    if (isEmpty()) {
        front = 0;
    }

    // Move rear circularly to the next position.
    rear = (rear + 1) % MAX_SIZE;

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

    // Reset both indices if this is the last element.
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        // Move front circularly to the next position.
        front = (front + 1) % MAX_SIZE;
    }
}

// Display elements in FIFO order.
void displayQueue() {
    if (isEmpty()) {
        cout << "Queue is empty!\n";
        return;
    }

    cout << "Circular Queue: ";

    int i = front;

    while (true) {
        cout << queueArray[i] << " ";

        if (i == rear) {
            break;
        }

        i = (i + 1) % MAX_SIZE;
    }

    cout << '\n';
}

int main() {
    cout << "========== CIRCULAR QUEUE ==========\n\n";

    // Fill the queue.
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    cout << '\n';
    displayQueue();

    // Remove two elements from the front.
    cout << '\n';
    dequeue();
    dequeue();

    displayQueue();

    // Reuse the empty spaces at the beginning.
    cout << '\n';
    enqueue(60);
    enqueue(70);

    displayQueue();

    // Try to insert when the queue is full.
    cout << '\n';
    enqueue(80);

    return 0;
}
