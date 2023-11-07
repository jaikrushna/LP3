#include <iostream>
using namespace std;

const int N = 5;

class NQueen {
public:
    bool isSafe(int row, int col, int board[N][N]) {
        for (int j = 0; j < N; j++) {
            if (board[row][j] == 1) {
                return false;
            }
        }
        for (int i = 0; i < N; i++) {
            if (board[i][col] == 1) {
                return false;
            }
        }
        int r = row;
        for (int c = col; c >= 0 && r >= 0; c--, r--) {
            if (board[r][c] == 1) {
                return false;
            }
        }
        r = row;
        for (int c = col; c < N && r >= 0; c++, r--) {
            if (board[r][c] == 1) {
                return false;
            }
        }
        r = row;
        for (int c = col; c >= 0 && r < N; c--, r++) {
            if (board[r][c] == 1) {
                return false;
            }
        }
        for (int c = col; c < N && r < N; c++, r++) {
            if (board[r][c] == 1) {
                return false;
            }
        }
        return true;
    }

    bool solveNQueens(int board[N][N], int col) {
        if (col >= N) {
            return true;
        }

        for (int i = 0; i < N; i++) {
            if (isSafe(i, col, board)) {
                board[i][col] = 1;
                if (solveNQueens(board, col + 1)) {
                    return true;
                }
                board[i][col] = 0;
            }
        }

        return false;
    }

    void printBoard(int board[N][N]) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    NQueen solver;
    int board[N][N] = {0};

    board[0][0] = 1;

    if (solver.solveNQueens(board, 1)) {
        cout << "Solution exists. The final 8-Queens matrix is:" << endl;
        solver.printBoard(board);
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}