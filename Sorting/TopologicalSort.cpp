
/*
 * Topological Sort arranges the vertices of a
 * Directed Acyclic Graph (DAG) in a valid order.
 *
 * Algorithm: Kahn's Algorithm
 */

#include <iostream>
using namespace std;

const int MAX_VERTICES = 10;

// Store the graph using an adjacency matrix.
int graph[MAX_VERTICES][MAX_VERTICES] = {0};

// Count the incoming edges of each vertex.
void calculateIndegree(int vertices, int indegree[]) {
    for (int i = 0; i < vertices; i++) {
        indegree[i] = 0;
    }

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (graph[i][j] == 1) {
                indegree[j]++;
            }
        }
    }
}

// Perform Topological Sort using Kahn's Algorithm.
void topologicalSort(int vertices) {
    int indegree[MAX_VERTICES];
    int queue[MAX_VERTICES];
    int order[MAX_VERTICES];

    calculateIndegree(vertices, indegree);

    int front = 0;
    int rear = 0;
    int count = 0;

    // Add all vertices with indegree zero to the queue.
    for (int i = 0; i < vertices; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // Process vertices from the queue.
    while (front < rear) {
        int current = queue[front++];

        order[count++] = current;

        // Remove the outgoing edges of the current vertex.
        for (int next = 0; next < vertices; next++) {
            if (graph[current][next] == 1) {
                indegree[next]--;

                // If indegree becomes zero, add the vertex.
                if (indegree[next] == 0) {
                    queue[rear++] = next;
                }
            }
        }
    }

    // A DAG must include every vertex in the result.
    if (count != vertices) {
        cout << "Topological Sort is not possible!\n";
        cout << "The graph contains a directed cycle.\n";
        return;
    }

    cout << "Topological Order: ";

    for (int i = 0; i < count; i++) {
        cout << order[i] << " ";
    }

    cout << '\n';
}

int main() {
    int vertices = 6;

    /*
     * Directed edges:
     * 5 -> 2
     * 5 -> 0
     * 4 -> 0
     * 4 -> 1
     * 2 -> 3
     * 3 -> 1
     */

    graph[5][2] = 1;
    graph[5][0] = 1;
    graph[4][0] = 1;
    graph[4][1] = 1;
    graph[2][3] = 1;
    graph[3][1] = 1;

    cout << "===== TOPOLOGICAL SORT =====\n\n";

    topologicalSort(vertices);

    return 0;
}
