#include <iostream>
using namespace std;

const int MAX = 20;
int N;
int solutionCount = 0;
char board[MAX][MAX];

// Check if it's safe to place a queen at (row, col)
bool isSafe(int row, int col) {
    // Check column
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q')
            return false;

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
        if (board[i][j] == 'Q')
            return false;

    return true;
}

// Print the board
void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

// Recursive backtracking
void solveNQueens(int row, bool printFirst) {
    if (row == N) {
        solutionCount++;
        if (printFirst) {
            cout << "One valid board configuration:\n";
            printBoard();
        }
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 'Q';
            solveNQueens(row + 1, printFirst && solutionCount == 0);
            board[row][col] = '.';
        }
    }
}

int main() {
    cout << "Enter value of N: ";
    cin >> N;

    // Initialize board
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = '.';

    solveNQueens(0, true);

    cout << "Total number of distinct solutions for N = " << N 
         << " is: " << solutionCount << endl;

    return 0;
}
