
/*
 * Description:
 * Introduces the Heap data structure and its
 * array representation using a Max Heap example.
 *
 * Key Concepts:
 * 1. Complete Binary Tree
 * 2. Max Heap Property
 * 3. Array Representation
 * 4. Parent and Child Index Formulas
 */

#include <iostream>
using namespace std;

int main() {
    // A Max Heap represented using a normal array.
    int heap[] = {50, 30, 40, 10, 20, 35, 25};

    int size = sizeof(heap) / sizeof(heap[0]);

    cout << "========== HEAP INTRODUCTION ==========\n\n";

    // Display the heap as an array.
    cout << "Array Representation: ";

    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }

    cout << "\n\n";

    // Display parent and child relationships.
    cout << "Parent-Child Relationships:\n";

    for (int i = 0; i < size; i++) {
        cout << "Node: " << heap[i];

        // Find the parent of the current node.
        if (i == 0) {
            cout << " | Parent: None";
        } else {
            int parent = (i - 1) / 2;
            cout << " | Parent: " << heap[parent];
        }

        // Find the left child.
        int leftChild = 2 * i + 1;

        if (leftChild < size) {
            cout << " | Left Child: " << heap[leftChild];
        } else {
            cout << " | Left Child: None";
        }

        // Find the right child.
        int rightChild = 2 * i + 2;

        if (rightChild < size) {
            cout << " | Right Child: " << heap[rightChild];
        } else {
            cout << " | Right Child: None";
        }

        cout << '\n';
    }

    cout << "\nTotal Nodes: " << size << '\n';
    cout << "Root Node: " << heap[0] << '\n';

    return 0;
}
