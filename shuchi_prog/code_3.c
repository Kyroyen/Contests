#include <stdio.h>

void printPascalsTriangle(int rows, int triangle[rows][rows]) {
    // Generate Pascal's Triangle
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <= i; j++) {
            // The edges of the triangle are always 1
            if (j == 0 || j == i) {
                triangle[i][j] = 1;
            } else {
                // Each element is the sum of the two above it
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }
    }

    // Print Pascal's Triangle
    for (int i = 0; i < rows; i++) {
        // Print spaces for alignment
        for (int k = 0; k < rows - i - 1; k++) {
            printf(" ");
        }
        for (int j = 0; j <= i; j++) {
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int numRows;

    // Get the number of rows from the user
    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &numRows);

    int triangle[numRows][numRows]; // Declare the triangle array in main

    printPascalsTriangle(numRows, triangle); // Pass the array BY REFERENCE!!!!!!!!

    return 0;
}
