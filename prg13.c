#include <stdio.h>
#include <conio.h>
#include <math.h>
#define MAX_QUEENS 30

int queens[MAX_QUEENS]; 
int count = 0;           // Number of valid solutions found

int isSafe(int row, int col) {
    for (int i = 1; i < col; i++) {
        // Check row and diagonal conflicts
        if (queens[i] == row || abs(queens[i] - row) == abs(i - col))
            return 0;
    }
    return 1;
}

void printSolution(int n) {
    count++;
    printf("\n\nSolution #%d:\n", count);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (queens[i] == j)
                printf("Q\t");
            else
                printf("*\t");
        }
        printf("\n");
    }
}

void solveNQueens(int n) {
    int col = 1;
    queens[col] = 0;

    while (col != 0) {
        queens[col]++;  
        while (queens[col] <= n && !isSafe(queens[col], col))
            queens[col]++;  

        if (queens[col] <= n) {
            if (col == n)
                printSolution(n);  
            else {
                col++;            
                queens[col] = 0; 
            }
        } else
            col--; 
    }
}

int main() {
    int n;
    clrscr();

    printf("Enter the number of queens (<= %d): ", MAX_QUEENS);
    scanf("%d", &n);

    if (n < 1 || n > MAX_QUEENS) {
        printf("Invalid input!\n");
        return 1;
    }

    solveNQueens(n);

    printf("\nTotal Solutions = %d\n", count);
    getch();
    return 0;
}
