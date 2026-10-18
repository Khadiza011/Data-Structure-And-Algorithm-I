
/*
 * Description:
 * This program introduces the Heap data structure,
 * its array representation, and parent-child relationships.
 *
 * Key Concepts:
 * 1. Complete Binary Tree
 * 2. Array Representation of a Heap
 * 3. Parent and Child Index Formulas
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Example of a Max Heap stored in an array.
    vector<int> heap = {50, 30, 40, 10, 20, 35, 25};

    int n = heap.size();

    cout << "========== HEAP INTRODUCTION ==========\n\n";

    // Display the heap as an array.
    cout << "Array Representation: ";

    for (int i = 0; i < n; i++) {
        cout << heap[i] << " ";
    }

    cout << "\n\n";

    // Explain the parent-child relationships.
    cout << "Parent-Child Relationships:\n";

    for (int i = 0; i < n; i++) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        cout << "Node: " << heap[i];

        if (i == 0) {
            cout << " | Parent: None";
        } else {
            int parent = (i - 1) / 2;
            cout << " | Parent: " << heap[parent];
        }

        if (leftChild < n) {
            cout << " | Left Child: " << heap[leftChild];
        } else {
            cout << " | Left Child: None";
        }

        if (rightChild < n) {
            cout << " | Right Child: " << heap[rightChild];
        } else {
            cout << " | Right Child: None";
        }

        cout << '\n';
    }

    cout << "\nTotal Nodes: " << n << '\n';
    cout << "Root Node: " << heap[0] << '\n';

    return 0;
}
