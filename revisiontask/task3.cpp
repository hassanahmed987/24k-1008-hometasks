#include <iostream>
using namespace std;

#define N 4

int maze[N][N] = {
    {1, 0, 1, 1},
    {1, 1, 0, 1},
    {0, 1, 1, 1},
    {1, 0, 1, 1}
};

int sol[N][N];  // To mark the solution path

bool isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

bool solveMaze(int x, int y) {
    // Destination reached
    if (x == N - 1 && y == N - 1) {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(x, y)) {
        sol[x][y] = 1;

        // Move Down
        if (solveMaze(x + 1, y))
            return true;

        // Move Right
        if (solveMaze(x, y + 1))
            return true;

        // Move Up
        if (solveMaze(x - 1, y))
            return true;

        // Move Left
        if (solveMaze(x, y - 1))
            return true;

        // Backtrack
        sol[x][y] = 0;
    }

    return false;
}

void printSolution() {
    cout << "Path the robot takes (1 = part of path):\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
}

int main() {
    if (solveMaze(0, 0))
        printSolution();
    else
        cout << "No path exists!\n";
    return 0;
}
 /* Q3b)
If multiple paths exist…
Backtracking explores all possible paths recursively, but the first successful path depends on the order of moves you define.
For example:
If your move order is Down → Right → Up → Left, it will always go down first whenever possible.
If you change it to Right → Down → Left → Up, it will prioritize rightward moves first.
Thus, if multiple valid paths exist, the algorithm follows the first successful one based on the movement priority. */
