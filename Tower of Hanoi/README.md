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
Move disk 1 from A to C

Total moves: 7
```

Here:

- `A` represents the source rod.
- `B` represents the auxiliary rod.
- `C` represents the destination rod.

The output shows the order in which each disk must be moved to solve the puzzle.

## 🔄 Step-by-Step Moves

Consider a Tower of Hanoi problem with three disks.

### Initial State

All disks are on rod A.

```text
    |          |          |
   [1]         |          |
  [ 2 ]        |          |
 [  3  ]       |          |
========   ========   ========
    A          B          C
```

### Move 1: Disk 1 from A to C

```text
    |          |          |
    |          |          |
  [ 2 ]        |          |
 [  3  ]       |         [1]
========   ========   ========
    A          B          C
```

### Move 2: Disk 2 from A to B

```text
    |          |          |
    |          |          |
    |          |          |
 [  3  ]      [ 2 ]      [1]
========   ========   ========
    A          B          C
```

### Move 3: Disk 1 from C to B

```text
    |          |          |
    |          |         [1]
    |          |        [ 2 ]
 [  3  ]       |          |
========   ========   ========
    A          B          C
```

### Move 4: Disk 3 from A to C

```text
    |          |          |
    |          |          |
    |          |          |
    |         [ 2 ]      [  3  ]
    |         [1]        ========
========   ========
    A          B          C
```

### Move 5: Disk 1 from B to A

```text
    |          |          |
    |          |          |
   [1]         |          |
  [ 2 ]        |        [  3  ]
========   ========   ========
    A          B          C
```

### Move 6: Disk 2 from B to C

```text
    |          |          |
    |          |          |
   [1]         |         [ 2 ]
    |          |        [  3  ]
========   ========   ========
    A          B          C
```

### Move 7: Disk 1 from A to C

```text
    |          |         [1]
    |          |        [ 2 ]
    |          |       [  3  ]
========   ========   ========
    A          B          C
```

**Final Result:** All three disks have been successfully transferred from rod A to rod C.

## 🔢 Minimum Number of Moves

The minimum number of moves required to solve the Tower of Hanoi problem with `n` disks is:

\[
T(n) = 2^n - 1
\]

Where:

- `T(n)` is the minimum number of moves.
- `n` is the number of disks.

### Examples

| Number of Disks | Minimum Moves |
|---:|---:|
| 1 | 1 |
| 2 | 3 |
| 3 | 7 |
| 4 | 15 |
| 5 | 31 |
| 10 | 1,023 |

Each additional disk approximately doubles the number of moves required.

## ⏱️ Time Complexity

The recurrence relation for the algorithm is:

\[
T(n) = 2T(n-1) + 1
\]

This is because the algorithm solves two subproblems of `n - 1` disks and performs one additional move for the largest disk.

Solving the recurrence gives:

\[
T(n) = 2^n - 1
\]

Therefore:

**Time Complexity: `O(2^n)`**

The time complexity is exponential because the number of moves grows exponentially as the number of disks increases.

## 💾 Space Complexity

Each recursive call reduces the number of disks by one. The maximum recursion depth is proportional to the number of disks.

**Auxiliary Space Complexity: `O(n)`**

This space is used by the recursive call stack. The implementation does not require an additional array to store the disks.

## 🛠️ Technologies Used

- **Programming Language:** C++
- **Header File:** `<iostream>`
- **Concepts:** Recursion, functions, base cases, recursive calls, and complexity analysis.

## 🚀 How to Run

1. Clone or download the repository.
2. Open `TowerOfHanoi.cpp` in your preferred C++ editor.
3. Compile the program:

   ```bash
   g++ -std=c++17 TowerOfHanoi.cpp -o TowerOfHanoi
   ```

4. Run the program.

   **Linux / macOS**

   ```bash
   ./TowerOfHanoi
   ```

   **Windows**

   ```bash
   TowerOfHanoi.exe
   ```

To test different numbers of disks, change the value of `disks` in the `main()` function. Note that the number of moves grows exponentially, so large inputs produce very long output.

## ⚠️ Important Notes

- The program assumes at least one disk.
- The three rod labels can be changed as needed.
- The minimum number of moves is `2^n - 1`.
- Tower of Hanoi is a classic example of a recursive algorithm.
- For large values of `n`, printing every move can take a considerable amount of time.

## 🎯 Learning Outcomes

After studying this project, beginners should be able to:

- Explain the Tower of Hanoi problem and its rules.
- Understand recursion and base cases.
- Write a recursive C++ solution.
- Trace the movement of disks step by step.
- Calculate the minimum number of moves.
- Derive the time and space complexity of a recursive algorithm.

## 📚 Summary

The Tower of Hanoi problem demonstrates how a complex task can be solved by breaking it into smaller, similar tasks.

By moving `n - 1` disks, transferring the largest disk, and then moving the smaller disks onto the destination rod, the recursive algorithm solves the problem in the minimum number of moves:

\[
\boxed{2^n - 1}
\]

---

**Author:** Khadiza011  
**Repository:** Data-Structure-And-Algorithm-I  
**Folder:** Tower of Hanoi  
**Language:** C++  
**Topic:** Recursion and Algorithm Analysis
