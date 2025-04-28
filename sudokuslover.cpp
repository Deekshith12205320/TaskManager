#include <iostream>
using namespace std;

const int N = 9;

// Function to print the Sudoku board
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

// Function to check if a number can be placed at board[row][col]
bool isSafe(int board[N][N], int row, int col, int num) {
    // Check if num is not repeated in the current row and column
    for (int x = 0; x < N; x++)
        if (board[row][x] == num || board[x][col] == num)
            return false;

    // Check if num is not repeated in the 3x3 sub-grid
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i + startRow][j + startCol] == num)
                return false;

    return true;
}

// Function to solve the Sudoku using backtracking
bool solveSudoku(int board[N][N]) {
    int row, col;

    // Check for an empty cell
    bool empty = false;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (board[row][col] == 0) {
                empty = true;
                break;
            }
        }
        if (empty)
            break;
    }

    // No empty cell left
    if (!empty)
        return true;

    // Try numbers 1 to 9 in the empty cell
    for (int num = 1; num <= N; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;

            // Recur to solve the rest of the board
            if (solveSudoku(board))
                return true;

            // If the number doesn't lead to a solution, reset and try the next number
            board[row][col] = 0;
        }
    }

    return false;
}

int main() {
    int board[N][N] = {0};

    cout << "Enter the Sudoku board values:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int num;
            cout << "Enter value for cell (" << i + 1 << ", " << j + 1 << ") [0 for empty]: ";
            cin >> num;
            board[i][j] = num;
        }
    }

    if (solveSudoku(board)) {
        cout << "Solved Sudoku:\n";
        printBoard(board);
    } else {
        cout << "No solution exists" << endl;
    }

    return 0;
}
