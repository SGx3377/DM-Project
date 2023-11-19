// Josephus in MultiDimension In C 
// Elimination Step is k-1 eliminate
#include <stdio.h>
#include <stdlib.h>

int** createGrid(int rows, int cols) {
    int** grid = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        grid[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            grid[i][j] = (i * cols) + j + 1;
        }
    }
    return grid;
}

void eliminate(int** grid, int rows, int cols, int step) {
    int totalPeople = rows * cols;
    int eliminated = 0;
    int currentIndex = 0;
    while (eliminated < totalPeople - 1) {
        int effectiveStep = step % (totalPeople - eliminated);
        if (effectiveStep == 0) {
            effectiveStep = totalPeople - eliminated;
        }
        currentIndex = (currentIndex + effectiveStep - 1) % (totalPeople - eliminated);

        int r = currentIndex / cols;
        int c = currentIndex % cols;
        printf("Eliminated: %d\n", grid[r][c]);

        // Remove the eliminated person from the grid
        for (int i = currentIndex; i < totalPeople - eliminated - 1; i++) {
            int currentRow = i / cols;
            int currentCol = i % cols;
            int nextRow = (i + 1) / cols;
            int nextCol = (i + 1) % cols;
            grid[currentRow][currentCol] = grid[nextRow][nextCol];
        }
        eliminated++;
    }
    printf("Survivor: %d\n", grid[0][0]); // Adjust this line for the final survivor position
}

void freeGrid(int** grid, int rows) {
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);
}

int main() {
    int rows, cols, step;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    printf("Enter the elimination step: ");
    scanf("%d", &step);

    int** grid = createGrid(rows, cols);
    eliminate(grid, rows, cols, step);
    freeGrid(grid, rows);

    return 0;
}
