# Linear Search

A beginner-friendly implementation of the **Linear Search algorithm in C++**. This project demonstrates how to search for a specific element in an array by checking each element sequentially.

## 📌 Overview

Linear Search is one of the simplest searching algorithms in computer science. It starts from the first element and compares each element with the target value until the element is found or the end of the array is reached.

It works with both sorted and unsorted arrays.

## ⚙️ How It Works

The algorithm follows these steps:

1. Start from the first element of the array.
2. Compare the current element with the target value.
3. If they match, return the element's index.
4. Otherwise, move to the next element.
5. If the target is not found after checking all elements, return `-1`.

## 💻 Example

**Input Array:**
```text
10 25 30 45 50 65
```

**Target Value:**
```text
45
```

**Output:**
```text
Element found!
Index: 3
Position: 4
```

The target value `45` is located at index `3`, which corresponds to position `4` because array indexing starts from zero in C++.

## 🧠 Algorithm

```text
LinearSearch(array, size, target)

1. For each index i from 0 to size - 1:
   a. If array[i] equals target:
      Return i
2. Return -1
```

## ⏱️ Time and Space Complexity

| Case | Complexity |
|---|---|
| Best Case | O(1) |
| Average Case | O(n) |
| Worst Case | O(n) |
| Auxiliary Space | O(1) |

- **Best Case:** The target is found at the first element.
- **Average Case:** Several elements must be checked before finding the target.
- **Worst Case:** The target is at the last position or does not exist in the array.
- **Space Complexity:** The algorithm uses constant extra space.

## ✅ Advantages

- Simple and easy to understand.
- Works with sorted and unsorted arrays.
- Requires no additional data structures.
- Suitable for small datasets.

## ⚠️ Limitations

- Can be slow for large datasets.
- May need to examine every element when the target is near the end or absent.

## 🛠️ Technologies Used

- **Language:** C++
- **Concepts:** Arrays, loops, conditional statements, functions, and searching algorithms.

## 🚀 How to Run

1. Clone or download this repository.
2. Open `LinearSearch.cpp` in a C++ compiler or IDE.
3. Compile the program using a C++ compiler:

   ```bash
   g++ LinearSearch.cpp -o LinearSearch
   ```

4. Run the executable:

   ```bash
   ./LinearSearch
   ```

   On Windows, run:

   ```bash
   LinearSearch.exe
   ```

## 🎯 Learning Objectives

After studying this implementation, beginners will understand how Linear Search works, how to find an element's index in an array, and how to analyze the time and space complexity of a basic searching algorithm.

---

