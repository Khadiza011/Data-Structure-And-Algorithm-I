
/*
 * Counting Sort sorts an array by counting
 * how many times each number appears.
 *
 * Note:
 * This program supports numbers from 0 to 100.
 */

#include <iostream>
using namespace std;

// Print all elements of the array.
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

// Sort the array using Counting Sort.
void countingSort(int arr[], int size) {
    const int MAX_VALUE = 100;

    // Store the frequency of each number.
    int count[MAX_VALUE + 1] = {0};

    // Count how many times each number appears.
    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }

    // Put the numbers back into the array in sorted order.
    int index = 0;

    for (int number = 0; number <= MAX_VALUE; number++) {

        // Insert the number as many times as it appears.
        while (count[number] > 0) {
            arr[index] = number;

            index++;
            count[number]--;
        }
    }
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "===== COUNTING SORT =====" << endl;

    cout << "Original Array: ";
    displayArray(arr, size);

    countingSort(arr, size);

    cout << "Sorted Array:   ";
    displayArray(arr, size);

    return 0;
}
