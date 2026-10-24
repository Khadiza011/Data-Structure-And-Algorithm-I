
/*
 * The goal is to move all disks from the source rod
 * to the destination rod using an auxiliary rod.
 *
 * Rules:
 * 1. Move only one disk at a time.
 * 2. Move only the top disk of a rod.
 * 3. Never place a larger disk on a smaller disk.
 */

#include <iostream>
using namespace std;

int totalMoves = 0;

// Solve the Tower of Hanoi problem recursively.
void towerOfHanoi(int n, char source,
                  char auxiliary, char destination) {

    // Base case: Only one disk remains.
    if (n == 1) {
        cout << "Move disk 1 from "
             << source << " to " << destination << '\n';

        totalMoves++;
        return;
    }

    // Step 1: Move the top n-1 disks to the auxiliary rod.
    towerOfHanoi(n - 1, source, destination, auxiliary);

    // Step 2: Move the largest remaining disk to destination.
    cout << "Move disk " << n << " from "
         << source << " to " << destination << '\n';

    totalMoves++;

    // Step 3: Move the n-1 disks onto the destination rod.
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int disks = 3;

    cout << "===== TOWER OF HANOI =====\n\n";
    cout << "Number of disks: " << disks << "\n\n";

    towerOfHanoi(disks, 'A', 'B', 'C');

    cout << "\nTotal moves: " << totalMoves << '\n';

    return 0;
}
