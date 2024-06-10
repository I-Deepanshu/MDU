#include <iostream>
#include <vector>

using namespace std;

// Function to check if it's safe to place a queen at row 'row' and column 'col'
bool isSafe(vector<int>& board, int row, int col) {
    // Check columns and diagonals
    for (int prevRow = 0; prevRow < row; ++prevRow) {
        int prevCol = board[prevRow];
        if (prevCol == col || abs(prevRow - row) == abs(prevCol - col))
            return false;
    }
    return true;
}

// Recursive function to solve the 8 Queens Problem
bool solveQueensUtil(vector<int>& board, int row) {
    if (row == board.size())
        return true;

    for (int col = 0; col < board.size(); ++col) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            if (solveQueensUtil(board, row + 1))
                return true;
        }
    }

    return false;
}

// Function to solve the 8 Queens Problem
void solveQueens() {
    vector<int> board(8, -1);

    if (solveQueensUtil(board, 0)) {
        cout << "Solution found:" << endl;
        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col)
                cout << (board[row] == col ? "Q " : "_ ");
            cout << endl;
        }
    } else {
        cout << "No solution exists." << endl;
    }
}

int main() {
    solveQueens();
    return 0;
}
