
/*
 * Description:
 * Implements a Max Heap using a normal array.
 * The largest element always stays at the root.
 *
 * Key Concepts:
 * 1. Max Heap Property
 * 2. Array Representation
 * 3. Insertion
 * 4. Heapify Up
 * 5. Accessing the Maximum Element
 */

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

// Display all elements of the Max Heap.
void displayHeap(int heap[], int size) {
    cout << "Max Heap: ";

    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }

    cout << '\n';
}

// Insert a new element into the Max Heap.
void insertHeap(int heap[], int &size, int value) {
    if (size == MAX_SIZE) {
        cout << "Heap is full!\n";
        return;
    }

    // Insert the new element at the end.
    int index = size;
    heap[size] = value;
    size++;

    // Move the element upward if it is larger than its parent.
    while (index > 0) {
        int parent = (index - 1) / 2;

        // Stop if the parent is already larger or equal.
        if (heap[parent] >= heap[index]) {
            break;
        }

        // Swap the parent and child.
        int temp = heap[parent];
        heap[parent] = heap[index];
        heap[index] = temp;

        // Continue from the parent's position.
        index = parent;
    }

    cout << value << " inserted successfully.\n";
}

// Return the largest element without removing it.
int getMax(int heap[], int size) {
    if (size == 0) {
        cout << "Heap is empty!\n";
        return -1;
    }

    return heap[0];
}

int main() {
    int heap[MAX_SIZE];
    int size = 0;

    cout << "========== MAX HEAP ==========\n\n";

    // Insert elements into the heap.
    insertHeap(heap, size, 30);
    insertHeap(heap, size, 10);
    insertHeap(heap, size, 50);
    insertHeap(heap, size, 20);
    insertHeap(heap, size, 40);

    cout << '\n';

    // Display the current heap.
    displayHeap(heap, size);

    // Display the largest element.
    cout << "Largest element: " << getMax(heap, size) << '\n';

    // Display the total number of elements.
    cout << "Total elements: " << size << '\n';

    return 0;
}
