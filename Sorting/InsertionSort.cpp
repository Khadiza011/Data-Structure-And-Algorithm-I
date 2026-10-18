
/*
 * Description:
 * Sorts an array in ascending order by taking one
 * element at a time and inserting it into its
 * correct position in the sorted part.
 *
 * Key Concepts:
 * 1. Sorted and Unsorted Parts
 * 2. Shifting Elements
 * 3. Inserting at the Correct Position
 */

#include <iostream>
using namespace std;

// Display all elements of the array.
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << '\n';
}

// Sort the array using Insertion Sort.
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        // Store the element to be inserted.
        int key = arr[i];

        int j = i - 1;

        // Shift elements greater than key to the right.
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert key into its correct position.
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "========== INSERTION SORT ==========\n\n";

    cout << "Original Array: ";
    displayArray(arr, size);

    // Sort the array.
    insertionSort(arr, size);

    cout << "Sorted Array:   ";
    displayArray(arr, size);

    return 0;
}
