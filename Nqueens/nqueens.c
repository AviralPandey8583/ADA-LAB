#include <stdio.h>

int board[20][20];
int N;
int solutionCount = 0;

void printBoard() {
    int i, j;
    printf("\nSolution %d:\n", ++solutionCount);
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int isSafe(int row, int col) {
    int i, j;
    for(i = 0; i < row; i++) {
        if(board[i][col] == 1)
            return 0;
    }
    for(i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 1)
            return 0;
    }
    for(i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
        if(board[i][j] == 1)
            return 0;
    }

    return 1;
}

void solveNQueens(int row) {
    int col;
    if(row == N) {
        printBoard();
        return;
    }

    for(col = 0; col < N; col++) {
        if(isSafe(row, col)) {
            board[row][col] = 1;
            solveNQueens(row + 1);
            board[row][col] = 0;
        }
    }
}

int main() {
    int i, j;
    printf("Enter value of N: ");
    scanf("%d", &N);
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }
    solveNQueens(0);
    printf("\nTotal Solutions = %d\n", solutionCount);
    return 0;
}
