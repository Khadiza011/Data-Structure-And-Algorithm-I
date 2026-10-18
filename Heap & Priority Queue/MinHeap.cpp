
/*
 * Description:
 * A Min Heap is a complete binary tree where
 * every parent is smaller than or equal to its children.
 */

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

// Display all elements of the heap.
void displayHeap(int heap[], int size) {
    cout << "Min Heap: ";

    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }

    cout << '\n';
}

// Insert a new element into the Min Heap.
void insertHeap(int heap[], int &size, int value) {
    if (size == MAX_SIZE) {
        cout << "Heap is full!\n";
        return;
    }

    // Insert the new element at the end.
    int index = size;
    heap[size] = value;
    size++;

    // Move the element upward to restore heap property.
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (heap[parent] <= heap[index]) {
            break;
        }

        int temp = heap[parent];
        heap[parent] = heap[index];
        heap[index] = temp;

        index = parent;
    }

    cout << value << " inserted successfully.\n";
}

// Return the smallest element.
int getMin(int heap[], int size) {
    if (size == 0) {
        cout << "Heap is empty!\n";
        return -1;
    }

    return heap[0];
}

int main() {
    int heap[MAX_SIZE];
    int size = 0;

    cout << "========== MIN HEAP ==========\n\n";

    insertHeap(heap, size, 30);
    insertHeap(heap, size, 10);
    insertHeap(heap, size, 50);
    insertHeap(heap, size, 20);
    insertHeap(heap, size, 5);

    cout << '\n';

    displayHeap(heap, size);

    cout << "Smallest element: " << getMin(heap, size) << '\n';
    cout << "Total elements: " << size << '\n';

    return 0;
}
