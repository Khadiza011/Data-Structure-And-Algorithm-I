#include <iostream>
using namespace std;

/* =========================
   BST NODE DEFINITION
   ========================= */
struct Node {
    double key;
    Node* left;
    Node* right;
    Node* parent;

    Node(double val) {
        key = val;
        left = right = parent = nullptr;
    }
};

/* =========================
   PREORDER TRAVERSAL
   ========================= */
void preorder(Node* root) {
    if (root != nullptr) {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

/* =========================
   BST INSERT
   ========================= */
void BST_Insert(Node*& root, Node* z) {
    Node* y = nullptr; // parent pointer
    Node* x = root;    // current pointer

    while (x != nullptr) {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;

    if (y == nullptr)
        root = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;
}

/* =========================
   BST SEARCH
   ========================= */
Node* BST_Search(Node* root, double key) {
    while (root != nullptr && root->key != key) {
        if (key < root->key)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

/* =========================
   MAXIMUM (for predecessor)
   ========================= */
Node* Tree_Maximum(Node* x) {
    while (x->right != nullptr)
        x = x->right;
    return x;
}

/* =========================
   PREDECESSOR
   ========================= */
Node* Tree_Predecessor(Node* x) {
    if (x->left != nullptr)
        return Tree_Maximum(x->left);

    Node* y = x->parent;
    while (y != nullptr && x == y->left) {
        x = y;
        y = y->parent;
    }
    return y;
}

/* =========================
   MAIN FUNCTION
   ========================= */
int main() {
    Node* root = nullptr;

    // Given floating-point values
    double values[] = {7.5, 3.2, 10.8, 1.4, 5.9, 9.1, 12.6};
    int n = sizeof(values) / sizeof(values[0]);

    // Insert values into BST
    for (int i = 0; i < n; i++)
        BST_Insert(root, new Node(values[i]));

    // Preorder Traversal
    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    // Find predecessor of 9.1
    Node* node = BST_Search(root, 9.1);
    Node* pred = Tree_Predecessor(node);

    cout << "Predecessor of 9.1: ";
    if (pred)
        cout << pred->key << endl;
    else
        cout << "None" << endl;

    return 0;
}
