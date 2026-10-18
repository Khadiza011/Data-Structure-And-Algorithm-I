
/*
 * Description:
 * Demonstrates Max Priority Queue and Min Priority Queue
 * using the C++ Standard Template Library (STL).
 *
 * Key Concepts:
 * 1. priority_queue
 * 2. push()
 * 3. top()
 * 4. pop()
 * 5. empty()
 * 6. size()
 */

#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main() {
    cout << "========== PRIORITY QUEUE (STL) ==========\n";

    // Max Priority Queue:
    // The largest element has the highest priority.
    priority_queue<int> maxPQ;

    maxPQ.push(30);
    maxPQ.push(10);
    maxPQ.push(50);
    maxPQ.push(20);
    maxPQ.push(40);

    cout << "\n--- MAX PRIORITY QUEUE ---\n";

    cout << "Highest priority element: " << maxPQ.top() << '\n';
    cout << "Total elements: " << maxPQ.size() << '\n';

    cout << "Elements in priority order: ";

    while (!maxPQ.empty()) {
        cout << maxPQ.top() << " ";
        maxPQ.pop();
    }

    cout << '\n';

    // Min Priority Queue:
    // The smallest element has the highest priority.
    priority_queue<int, vector<int>, greater<int>> minPQ;

    minPQ.push(30);
    minPQ.push(10);
    minPQ.push(50);
    minPQ.push(20);
    minPQ.push(40);

    cout << "\n--- MIN PRIORITY QUEUE ---\n";

    cout << "Highest priority element: " << minPQ.top() << '\n';
    cout << "Total elements: " << minPQ.size() << '\n';

    cout << "Elements in priority order: ";

    while (!minPQ.empty()) {
        cout << minPQ.top() << " ";
        minPQ.pop();
    }

    cout << '\n';

    return 0;
}
