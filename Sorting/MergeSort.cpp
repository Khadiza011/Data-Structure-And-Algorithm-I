
/*
 * Merge Sort divides an array into smaller parts,
 * sorts them, and merges them in sorted order.
 */

#include <iostream>
using namespace std;

// Merge two sorted parts of the array.
void merge(int arr[], int left, int mid, int right) {
    int temp[100];

    int i = left;      // Starting index of the left part.
    int j = mid + 1;   // Starting index of the right part.
    int k = 0;         // Index for the temporary array.

    // Compare elements from both parts.
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }

        k++;
    }

    // Copy any remaining elements from the left part.
    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Copy any remaining elements from the right part.
    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copy the sorted elements back into the original array.
    for (int p = 0; p < k; p++) {
        arr[left + p] = temp[p];
    }
}

// Divide the array and sort each part.
void mergeSort(int arr[], int left, int right) {
    // Stop when only one element remains.
    if (left >= right) {
        return;
    }

    // Find the middle index.
    int mid = left + (right - left) / 2;

    // Sort the left half.
    mergeSort(arr, left, mid);

    // Sort the right half.
    mergeSort(arr, mid + 1, right);

    // Merge both sorted halves.
    merge(arr, left, mid, right);
}

// Display the array.
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << '\n';
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "===== MERGE SORT =====\n\n";

    cout << "Original Array: ";
    displayArray(arr, size);

    // Sort the entire array.
    mergeSort(arr, 0, size - 1);

    cout << "Sorted Array:   ";
    displayArray(arr, size);

    return 0;
}
