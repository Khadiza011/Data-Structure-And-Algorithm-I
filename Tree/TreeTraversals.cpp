
/*
 * Topic: Tree Traversals
 * File: TreeTraversals.cpp
 *
 * Tree traversal means visiting every node
 * of a tree in a specific order.
 *
 * This program demonstrates:
 * 1. Preorder Traversal
 * 2. Inorder Traversal
 * 3. Postorder Traversal
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

// Preorder: Root -> Left -> Right
void preorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";

    preorder(root->left);
    preorder(root->right);
}

// Inorder: Left -> Root -> Right
void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

// Postorder: Left -> Right -> Root
void postorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    postorder(root->left);
    postorder(root->right);

    cout << root->data << " ";
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
     * Create this tree:
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

    cout << "===== TREE TRAVERSALS =====\n\n";

    cout << "Preorder:  ";
    preorder(root);

    cout << "\nInorder:   ";
    inorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    cout << '\n';

    deleteTree(root);

    return 0;
}
