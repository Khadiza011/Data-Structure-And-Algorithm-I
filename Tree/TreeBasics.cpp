
/*
 * Topic: Tree Basics
 * File: TreeBasics.cpp
 *
 * A Tree is a non-linear data structure made of nodes
 * connected by edges.
 *
 * This program creates a simple tree and displays
 * its nodes and relationships.
 */

#include <iostream>
using namespace std;

// Define the structure of a tree node.
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

// Display the root and its immediate children.
void displayTree(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty!\n";
        return;
    }

    cout << "Root: " << root->data << '\n';

    if (root->left != nullptr) {
        cout << "Left child of " << root->data
             << ": " << root->left->data << '\n';
    }

    if (root->right != nullptr) {
        cout << "Right child of " << root->data
             << ": " << root->right->data << '\n';
    }

    if (root->left != nullptr &&
        root->left->left == nullptr &&
        root->left->right == nullptr) {
        cout << root->left->data << " is a leaf node.\n";
    }

    if (root->right != nullptr &&
        root->right->left == nullptr &&
        root->right->right == nullptr) {
        cout << root->right->data << " is a leaf node.\n";
    }
}

// Free all nodes to release allocated memory.
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
     * Create this tree:
     *
     *        1
     *       / \
     *      2   3
     */

    Node* root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    cout << "===== TREE BASICS =====\n\n";

    displayTree(root);

    // Release the memory used by the tree.
    deleteTree(root);

    return 0;
}
