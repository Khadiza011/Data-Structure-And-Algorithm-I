
/*
 * Description:
 * Searches for a target value in an array by
 * checking each element one by one.
 *
 * Key Concepts:
 * 1. Linear Search Algorithm
 * 2. Array Traversal
 * 3. Finding an Element's Position
 */

#include <iostream>
using namespace std;

// Search for a target value in the array.
// Return its index if found; otherwise, return -1.
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        // Check whether the current element matches.
        if (arr[i] == target) {
            return i;
        }
    }

    // The target was not found.
    return -1;
}

// Display all array elements.
void displayArray(int arr[], int size) {
    cout << "Array: ";

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << '\n';
}

int main() {
    int arr[] = {10, 25, 30, 45, 50, 65};
    int size = sizeof(arr) / sizeof(arr[0]);

    int target = 45;

    cout << "========== LINEAR SEARCH ==========\n\n";

    displayArray(arr, size);

    cout << "Searching for: " << target << '\n';

    int index = linearSearch(arr, size, target);

    if (index != -1) {
        cout << "Element found!\n";
        cout << "Index: " << index << '\n';
        cout << "Position: " << index + 1 << '\n';
    } else {
        cout << "Element not found!\n";
    }

    // Search for an element that does not exist.
    target = 100;

    cout << "\nSearching for: " << target << '\n';

    index = linearSearch(arr, size, target);

    if (index != -1) {
        cout << "Element found at index " << index << ".\n";
    } else {
        cout << "Element not found!\n";
    }

    return 0;
}
