
/*
 * Description:
 * Demonstrates Binary Search and the STL functions
 * lower_bound(), upper_bound(), and binary_search().
 *
 * Important:
 * The array must be sorted in ascending order.
 */

#include <iostream>
#include <algorithm>
using namespace std;

// Perform Binary Search using a normal array.
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            // Search the right half.
            left = mid + 1;
        } else {
            // Search the left half.
            right = mid - 1;
        }
    }

    return -1;
}

// Display the array.
void displayArray(int arr[], int size) {
    cout << "Array: ";

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << '\n';
}

int main() {
    int arr[] = {10, 20, 20, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    int target = 20;

    cout << "========== BINARY SEARCH ==========\n\n";

    displayArray(arr, size);

    // Manual Binary Search.
    int index = binarySearch(arr, size, target);

    cout << "\nSearching for: " << target << '\n';

    if (index != -1) {
        cout << "Element found at index: " << index << '\n';
    } else {
        cout << "Element not found!\n";
    }

    // Find the first element greater than or equal to target.
    int* lower = lower_bound(arr, arr + size, target);

    // Find the first element strictly greater than target.
    int* upper = upper_bound(arr, arr + size, target);

    cout << "\nlower_bound index: " << lower - arr << '\n';
    cout << "upper_bound index: " << upper - arr << '\n';

    cout << "First occurrence of " << target
         << ": index " << lower - arr << '\n';

    cout << "Number of occurrences of " << target
         << ": " << upper - lower << '\n';

    // Check whether the target exists.
    if (binary_search(arr, arr + size, target)) {
        cout << target << " exists in the array.\n";
    } else {
        cout << target << " does not exist in the array.\n";
    }

    return 0;
}
