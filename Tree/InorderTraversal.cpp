
/*
 * Topic: Inorder Traversal
 * File: InorderTraversal.cpp
 *
 * Inorder Traversal visits nodes in this order:
 * 1. Left Subtree
 * 2. Root
 * 3. Right Subtree
 */

#include <iostream>
using namespace std;

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

// Perform Inorder Traversal.
void inorder(Node* root) {
    // Stop if the node does not exist.
    if (root == nullptr) {
        return;
    }

    // Step 1: Visit the left subtree.
    inorder(root->left);

    // Step 2: Visit the root.
    cout << root->data << " ";

    // Step 3: Visit the right subtree.
    inorder(root->right);
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
     *      / \
     *     4   5
     */

    Node* root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    cout << "===== INORDER TRAVERSAL =====\n\n";

    cout << "Traversal Order: ";
    inorder(root);

    cout << '\n';

    deleteTree(root);

    return 0;
}
