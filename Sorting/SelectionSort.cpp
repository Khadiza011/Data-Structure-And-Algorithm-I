
/*
 * Description:
 * Sorts an array in ascending order by repeatedly
 * finding the minimum element from the unsorted part
 * and placing it in the correct position.
 *
 * Key Concepts:
 * 1. Finding the Minimum Element
 * 2. Swapping Elements
 * 3. Nested Loops
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

// Sort the array using Selection Sort.
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        // Assume the current position has the minimum value.
        int minIndex = i;

        // Find the minimum element in the unsorted part.
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Place the minimum element at the current position.
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "========== SELECTION SORT ==========\n\n";

    cout << "Original Array: ";
    displayArray(arr, size);

    // Sort the array.
    selectionSort(arr, size);

    cout << "Sorted Array:   ";
    displayArray(arr, size);

    return 0;
}
