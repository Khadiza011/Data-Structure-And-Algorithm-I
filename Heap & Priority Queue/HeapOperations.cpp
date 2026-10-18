
/*
 * Description:
 * Implements the main operations of a Max Heap
 * using a normal array.
 *
 * Operations:
 * 1. Insert an element
 * 2. Get the maximum element
 * 3. Delete the maximum element
 * 4. Heapify Up
 * 5. Heapify Down
 * 6. Display the heap
 */

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

// Display all elements of the heap.
void displayHeap(int heap[], int size) {
    if (size == 0) {
        cout << "Heap is empty!\n";
        return;
    }

    cout << "Max Heap: ";

    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }

    cout << '\n';
}

// Restore the Max Heap property upward.
void heapifyUp(int heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (heap[parent] >= heap[index]) {
            break;
        }

        int temp = heap[parent];
        heap[parent] = heap[index];
        heap[index] = temp;

        index = parent;
    }
}

// Restore the Max Heap property downward.
void heapifyDown(int heap[], int size, int index) {
    while (true) {
        int largest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        // Check whether the left child is larger.
        if (leftChild < size &&
            heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }

        // Check whether the right child is larger.
        if (rightChild < size &&
            heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }

        // Stop if the current node is already the largest.
        if (largest == index) {
            break;
        }

        int temp = heap[index];
        heap[index] = heap[largest];
        heap[largest] = temp;

        // Continue from the swapped child's position.
        index = largest;
    }
}

// Insert a new element into the Max Heap.
void insertHeap(int heap[], int &size, int value) {
    if (size == MAX_SIZE) {
        cout << "Heap is full!\n";
        return;
    }

    heap[size] = value;
    size++;

    heapifyUp(heap, size - 1);

    cout << value << " inserted successfully.\n";
}

// Return the maximum element without deleting it.
int getMax(int heap[], int size) {
    if (size == 0) {
        cout << "Heap is empty!\n";
        return -1;
    }

    return heap[0];
}

// Delete and return the maximum element.
int deleteMax(int heap[], int &size) {
    if (size == 0) {
        cout << "Heap is empty!\n";
        return -1;
    }

    int maximum = heap[0];

    // Move the last element to the root.
    heap[0] = heap[size - 1];
    size--;

    // Restore the Max Heap property.
    if (size > 0) {
        heapifyDown(heap, size, 0);
    }

    return maximum;
}

int main() {
    int heap[MAX_SIZE];
    int size = 0;

    cout << "========== HEAP OPERATIONS ==========\n\n";

    // Insert elements.
    insertHeap(heap, size, 30);
    insertHeap(heap, size, 10);
    insertHeap(heap, size, 50);
    insertHeap(heap, size, 20);
    insertHeap(heap, size, 40);

    cout << '\n';
    displayHeap(heap, size);

    // Access the maximum element.
    cout << "\nMaximum element: " << getMax(heap, size) << '\n';

    // Delete the maximum element.
    int removed = deleteMax(heap, size);

    if (removed != -1) {
        cout << "Deleted maximum: " << removed << '\n';
    }

    // Display the heap after deletion.
    displayHeap(heap, size);

    cout << "Remaining elements: " << size << '\n';

    return 0;
}
