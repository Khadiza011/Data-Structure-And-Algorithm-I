# Tower of Hanoi

A beginner-friendly C++ implementation of the **Tower of Hanoi problem** using recursion. This project explains the problem, its rules, recursive algorithm, step-by-step disk movements, and time and space complexity.

## 📌 Overview

The Tower of Hanoi is a classic mathematical puzzle used to understand **recursion** and problem-solving techniques in computer science.

The puzzle consists of three rods and a number of disks of different sizes. Initially, all disks are stacked on the source rod, with the largest disk at the bottom and the smallest at the top.

The goal is to move all disks from the source rod to the destination rod using the auxiliary rod, following the rules of the puzzle.

## 🎯 Objectives

- Understand the concept of recursion.
- Learn how to solve a problem by dividing it into smaller subproblems.
- Identify the base case and recursive cases.
- Understand the movement of disks between three rods.
- Analyze the time and space complexity of a recursive algorithm.

## 🧩 Problem Description

There are three rods:

- **Source (A):** The rod containing all disks initially.
- **Auxiliary (B):** The temporary rod used during the process.
- **Destination (C):** The rod where all disks must be moved.

The objective is to transfer all disks from rod A to rod C while following the rules.

### Rules of Tower of Hanoi

1. Only one disk can be moved at a time.
2. Only the top disk of a rod can be moved.
3. A larger disk cannot be placed on top of a smaller disk.
4. All disks must be transferred from the source rod to the destination rod.

## 🧠 Core Concept: Recursion

**Recursion** is a programming technique in which a function calls itself to solve smaller versions of the same problem.

For the Tower of Hanoi problem, moving `n` disks requires three steps:

1. Move the top `n - 1` disks from the source rod to the auxiliary rod.
2. Move the largest disk from the source rod to the destination rod.
3. Move the `n - 1` disks from the auxiliary rod to the destination rod.

The same process is repeated until only one disk remains.

### Base Case

The base case occurs when there is only one disk to move.

```cpp
if (n == 1) {
    cout << "Move disk 1 from "
         << source << " to " << destination << '\n';
    return;
}
```

When `n == 1`, the disk can be moved directly to the destination rod, so no further recursive call is required.

## ⚙️ Algorithm

The recursive algorithm follows these steps:

```text
TowerOfHanoi(n, source, auxiliary, destination)

1. If n == 1:
      Move disk 1 from source to destination.
      Return.

2. Move n - 1 disks from source to auxiliary,
   using destination as the auxiliary rod.

3. Move disk n from source to destination.

4. Move n - 1 disks from auxiliary to destination,
   using source as the auxiliary rod.

5. Stop when all disks have been moved.
```

## ▶️ Sample Output

```text
===== TOWER OF HANOI =====

Number of disks: 3

Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from
