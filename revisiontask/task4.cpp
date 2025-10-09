#include <iostream>
using namespace std;

#define N 4

int maze[N][N] = {
    {1, 1, 0, 1},
    {0, 1, 1, 0},
    {1, 1, 0, 1},
    {0, 1, 1, 1}
};

int sol[N][N]; 

bool isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

bool solveMaze(int x, int y) {
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(x, y)) {
        sol[x][y] = 1;  

        if (solveMaze(x, y + 1))
            return true;

        if (solveMaze(x + 1, y))
            return true;

        if (solveMaze(x, y - 1))
            return true;

        if (solveMaze(x - 1, y))
            return true;

        sol[x][y] = 0;
        return false;
    }

    return false;
}

int main() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            sol[i][j] = 0;

    if (solveMaze(0, 0)) {
        cout << "Safe escape path found:\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << sol[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "No safe path exists! The person is trapped.\n";
    }

    return 0;

  /* Q4b)
How Backtracking Works:
Start at (0,0).
Try all possible directions (right → down → left → up).
If a move leads to a dead end (no more safe cells), the algorithm goes back (backtracks) and tries another route.
This continues until:
The exit (3,3) is reached → success
Or no path remains → trapped  */
}
