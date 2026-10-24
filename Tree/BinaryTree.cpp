
/*
 * Topic: Binary Tree
 * File: BinaryTree.cpp
 *
 * A Binary Tree is a tree data structure in which
 * each node can have at most two children:
 * a left child and a right child.
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

// Count the total number of nodes.
int countNodes(Node* root) {
    // An empty tree has zero nodes.
    if (root == nullptr) {
        return 0;
    }

    // Count the root, left subtree, and right subtree.
    return 1 + countNodes(root->left)
             + countNodes(root->right);
}

// Display the tree using an inorder traversal.
void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Free the memory used by the tree.
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

    cout << "===== BINARY TREE =====\n\n";

    cout << "Inorder Traversal: ";
    inorder(root);

    cout << "\nTotal Nodes: " << countNodes(root) << '\n';

    deleteTree(root);

    return 0;
}
