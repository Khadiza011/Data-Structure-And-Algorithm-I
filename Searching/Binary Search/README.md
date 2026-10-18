# Binary Search

A beginner-friendly implementation of **Binary Search in C++**, including the STL functions `lower_bound()`, `upper_bound()`, and `binary_search()`.

## 📌 Overview

Binary Search is an efficient searching algorithm that finds an element in a **sorted array** by repeatedly dividing the search range into two halves.

Instead of checking every element one by one, Binary Search compares the target with the middle element and eliminates half of the remaining search range in each iteration.

## ⚙️ How Binary Search Works

The algorithm follows these steps:

1. Set `left` to the first index and `right` to the last index.
2. Calculate the middle index using `left + (right - left) / 2`.
3. Compare the middle element with the target value.
4. If they match, return the middle index.
5. If the target is greater, search the right half.
6. If the target is smaller, search the left half.
7. Repeat until the element is found or the search range becomes empty.

## 💻 Example

**Input Array:**

```text
10 20 20 20 30 40 50
```

**Target Value:**

```text
20
```

**Output:**

```text
Element found at index: 3

lower_bound index: 1
upper_bound index: 4

First occurrence of 20: index 1
Number of occurrences of 20: 3

20 exists in the array.
```

The manual Binary Search implementation may return any matching occurrence when duplicate values exist. In this example, it returns index `3`, while `lower_bound()` identifies the first occurrence at index `1`.

## 🧠 Binary Search Algorithm

```text
BinarySearch(array, size, target)

1. Set left = 0
2. Set right = size - 1

3. While left <= right:
   a. Calculate mid = left + (right - left) / 2

   b. If array[mid] == target:
      Return mid

   c. If array[mid] < target:
      Set left = mid + 1

   d. Otherwise:
      Set right = mid - 1

4. Return -1 if the target is not found
```

## 🔍 STL Searching Functions

C++ provides useful searching functions through the `<algorithm>` header.

### 1. `lower_bound()`

Returns an iterator pointing to the first element that is **greater than or equal to** the target value.

```cpp
int* result = lower_bound(arr, arr + size, target);
int index = result - arr;
```

### 2. `upper_bound()`

Returns an iterator pointing to the first element that is **strictly greater than** the target value.

```cpp
int* result = upper_bound(arr, arr + size, target);
int index = result - arr;
```

### 3. `binary_search()`

Checks whether the target value exists in the sorted range. It returns `true` if found and `false` otherwise.

```cpp
bool found = binary_search(arr, arr + size, target);
```

### 4. Count Duplicate Elements

The difference between `upper_bound()` and `lower_bound()` gives the number of occurrences of a value.

```cpp
int count = upper_bound(arr, arr + size, target)
          - lower_bound(arr, arr + size, target);
```

**Important:** These STL functions require the array to be sorted according to the same ordering used for searching.

## 📊 Time and Space Complexity

| Algorithm / Function | Time Complexity |
|---|---|
| Manual Binary Search | O(log n) |
| `lower_bound()` | O(log n) |
| `upper_bound()` | O(log n) |
| `binary_search()` | O(log n) |
| Auxiliary Space (manual implementation) | O(1) |

## ✅ Advantages

- Faster than Linear Search for large sorted datasets.
- Reduces the search range by half in each iteration.
- Requires constant extra space in the iterative implementation.
- STL functions simplify common searching operations.

## ⚠️ Limitations

- The array must be sorted before searching.
- Maintaining sorted order can add overhead when elements are frequently inserted or deleted.
- Binary Search is not directly suitable for an ordinary unsorted array.

## 🛠️ Technologies Used

- **Language:** C++
- **Header Files:** `<iostream>`, `<algorithm>`
- **Concepts:** Arrays, loops, conditional statements, functions, iterators, and searching algorithms.

## 🚀 How to Run

1. Clone or download the repository.
2. Open `BinarySearch.cpp` in your preferred C++ IDE or editor.
3. Compile the program using a C++ compiler:

   ```bash
   g++ -std=c++17 BinarySearch.cpp -o BinarySearch
   ```

4. Run the executable:

   **Linux / macOS**
   ```bash
   ./BinarySearch
   ```

   **Windows**
   ```bash
   BinarySearch.exe
   ```

## 🎯 Learning Objectives

After completing this example, beginners will understand:

- How Binary Search works step by step.
- Why sorted data is necessary.
- How to implement Binary Search using a normal array.
- The difference between `lower_bound()` and `upper_bound()`.
- How to find the first occurrence and count duplicate elements.
- How to analyze searching algorithms using time and space complexity.

---
