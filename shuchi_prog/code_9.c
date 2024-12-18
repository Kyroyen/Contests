#include <stdio.h>

#define MAX 100 // Define maximum size for matrix dimensions

// Function to transpose the matrix using pointer-to-pointer
void transposeMatrix(int matrix[MAX][MAX], int transposed[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j]; // Transposing: matrix[i][j] to transposed[j][i]
        }
    }
}

// Function to print the matrix
void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[MAX][MAX], transposed[MAX][MAX];
    int rows, cols;

    // Input dimensions of the matrix
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Input elements for the matrix
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Print the original matrix
    printf("Original Matrix:\n");
    printMatrix(matrix, rows, cols);

    // Perform the transposition
    transposeMatrix(matrix, transposed, rows, cols);

    // Print the transposed matrix
    printf("Transposed Matrix:\n");
    printMatrix(transposed, cols, rows);

    return 0;
}
