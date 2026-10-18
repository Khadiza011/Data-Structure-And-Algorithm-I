
/*
 * Heap Sort uses a Max Heap to sort an array
 * in ascending order.
 *
 * A Max Heap is a binary tree where every parent
 * is greater than or equal to its children.
 */

#include <iostream>
using namespace std;

// Swap two elements.
void swapElements(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Maintain the Max Heap property.
void heapify(int arr[], int size, int root) {
    int largest = root;

    int left = 2 * root + 1;
    int right = 2 * root + 2;

    // Check whether the left child is larger.
    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }

    // Check whether the right child is larger.
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    // If a child is larger, swap and fix the heap.
    if (largest != root) {
        swapElements(arr[root], arr[largest]);

        heapify(arr, size, largest);
    }
}

// Sort the array using Heap Sort.
void heapSort(int arr[], int size) {
    // Step 1: Build a Max Heap.
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }

    // Step 2: Move the largest element to the end.
    for (int i = size - 1; i > 0; i--) {
        swapElements(arr[0], arr[i]);

        // Restore the Max Heap in the remaining array.
        heapify(arr, i, 0);
    }
}

// Display the array.
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << '\n';
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "===== HEAP SORT =====\n\n";

    cout << "Original Array: ";
    displayArray(arr, size);

    heapSort(arr, size);

    cout << "Sorted Array:   ";
    displayArray(arr, size);

    return 0;
}
