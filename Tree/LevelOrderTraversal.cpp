
/*
 * Topic: Level Order Traversal
 * File: LevelOrderTraversal.cpp
 *
 * Level Order Traversal visits tree nodes
 * level by level, from left to right.
 *
 * This program uses an array-based Queue.
 */

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

// Define a Binary Tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create a new node.
Node* createNode(int value) {
    Node* newNode = new Node;

    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;

    return newNode;
}

// Perform Level Order Traversal using a Queue.
void levelOrder(Node* root) {
    // An empty tree has nothing to display.
    if (root == nullptr) {
        cout << "Tree is empty!\n";
        return;
    }

    // Create a Queue using an array.
    Node* queue[MAX_SIZE];

    int front = 0;
    int rear = 0;

    // Insert the root into the Queue.
    queue[rear++] = root;

    cout << "Level Order Traversal: ";

    // Process nodes until the Queue becomes empty.
    while (front < rear) {
        // Remove the first node from the Queue.
        Node* current = queue[front++];

        // Visit the current node.
        cout << current->data << " ";

        // Add the left child to the Queue.
        if (current->left != nullptr) {
            queue[rear++] = current->left;
        }

        // Add the right child to the Queue.
        if (current->right != nullptr) {
            queue[rear++] = current->right;
        }
    }

    cout << '\n';
}

// Free all nodes from memory.
void deleteTree(Node* root) {
    if (root == nullptr) {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);

    delete root;
}

int main() {
    /*
     * Create this Binary Tree:
     *
     *         1
     *        / \
     *       2   3
     *      / \   \
     *     4   5   6
     */

    Node* root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    cout << "===== LEVEL ORDER TRAVERSAL =====\n\n";

    levelOrder(root);

    deleteTree(root);

    return 0;
}
