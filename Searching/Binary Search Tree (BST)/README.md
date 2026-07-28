# Binary Search Tree (BST)

## Overview

This project implements a **Binary Search Tree (BST)** using C++. The program allows users to insert floating-point values into the BST, display the tree using **Preorder Traversal**, and find the **predecessor** of a specified node.

The predecessor of a node is the node with the largest key that is smaller than the given key.

## Algorithm

### BST Insertion

1. Start from the root.
2. Compare the new key with the current node.
3. Move to the left child if the key is smaller; otherwise move to the right child.
4. Insert the node at the appropriate position.

### BST Search

1. Start from the root.
2. Compare the target key with the current node.
3. Continue searching left or right until the key is found or the tree ends.

### Finding the Predecessor

1. If the node has a left subtree:
   - The predecessor is the maximum value in the left subtree.
2. Otherwise:
   - Move upward using parent pointers until finding an ancestor where the node lies in its right subtree.
3. That ancestor is the predecessor.

## Time Complexity

| Operation | Time Complexity |
|----------|-----------------|
| Insertion | O(h) |
| Search | O(h) |
| Predecessor | O(h) |
| Preorder Traversal | O(n) |

Where:
- **n** = Number of nodes
- **h** = Height of the tree

## Input

- Number of nodes
- Floating-point values
- Key whose predecessor is to be found

### Example Input

```
Enter the number of nodes:
7

Enter the node values:
7.5
3.2
10.8
1.4
5.9
9.1
12.6

Enter the value to find its predecessor:
9.1
```

## Example Output

```
Preorder:
7.5 3.2 1.4 5.9 10.8 9.1 12.6

Predecessor of 9.1:
7.5
```

## How to Compile

```bash
g++ main.cpp -o main
```

## How to Run

### Linux/macOS

```bash
./main
```

### Windows

```bash
main.exe
```

## Features

- User input for node values
- Binary Search Tree insertion
- Preorder traversal
- BST search operation
- Finds the predecessor of a given node
- Supports floating-point values
- Simple C++ implementation
