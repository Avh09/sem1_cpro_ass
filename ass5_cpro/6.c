#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Define a struct to represent a matrix
struct Matrix {
    int rows;
    int cols;
    int data[MAX_SIZE][MAX_SIZE];
};

// Function to calculate the determinant of a matrix
double determinant(struct Matrix mat);

int main() {
    struct Matrix mat;

    printf("Enter the number of rows for the matrix: ");
    scanf("%d", &mat.rows);

    printf("Enter the number of columns for the matrix: ");
    scanf("%d", &mat.cols);

    // Input the matrix elements
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < mat.rows; ++i) {
        for (int j = 0; j < mat.cols; ++j) {
            printf("Enter element mat.data[%d][%d]: ", i, j);
            scanf("%d", &mat.data[i][j]);
        }
    }

    // Check if the matrix is square (number of rows = number of columns)
    if (mat.rows != mat.cols) {
        printf("Error: The matrix is not square. Determinant is undefined.\n");
        return 1;
    }

    // Calculate and display the determinant
    double det = determinant(mat);
    printf("Determinant: %lf\n", det);

    return 0;
}

// Recursive function to calculate determinant of a matrix
double determinant(struct Matrix mat) {
    if (mat.rows == 1) {
        return mat.data[0][0];
    }

    if (mat.rows == 2) {
        return mat.data[0][0] * mat.data[1][1] - mat.data[0][1] * mat.data[1][0];
    }

    double det = 0;

    for (int i = 0; i < mat.cols; ++i) {
        // Create a submatrix by excluding the current row and column
        struct Matrix submatrix;
        submatrix.rows = mat.rows - 1;
        submatrix.cols = mat.cols - 1;

        for (int j = 1; j < mat.rows; ++j) {
            int submatrixRow = 0;
            for (int k = 0; k < mat.cols; ++k) {
                if (k != i) {
                    submatrix.data[submatrixRow][k < i ? k : k - 1] = mat.data[j][k];
                }
            }
            ++submatrixRow;
        }

        // Calculate the cofactor
        int cofactorSign = (i % 2 == 0) ? 1 : -1;
        double cofactor = cofactorSign * mat.data[0][i] * determinant(submatrix);

        // Accumulate the determinant with the cofactor
        det += cofactor;
    }

    return det;
}
