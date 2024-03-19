#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Define a struct to represent the matrix
typedef struct {
    int data[MAX_SIZE][MAX_SIZE];
} Matrix;

// Function to calculate the determinant of a matrix
double determinant(Matrix *mat, int n);

int main() {
    int n;

    printf("Enter the size of the square matrix (n): ");
    scanf("%d", &n);

    // Input the matrix elements
    printf("Enter the elements of the matrix:\n");
    Matrix matrix;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("Enter element matrix.data[%d][%d]: ", i, j);
            scanf("%d", &matrix.data[i][j]);
        }
    }

    // Calculate and display the determinant
    double det = determinant(&matrix, n);
    printf("Determinant: %lf\n", det);

    return 0;
}

// Recursive function to calculate determinant of a matrix
double determinant(Matrix *mat, int n) {
    if (n == 1) {
        return mat->data[0][0];
    }

    if (n == 2) {
        return mat->data[0][0] * mat->data[1][1] - mat->data[0][1] * mat->data[1][0];
    }

    double det = 0;

    for (int i = 0; i < n; ++i) {
        // Calculate the cofactor
        int cofactorSign = (i % 2 == 0) ? 1 : -1;
        double cofactor = cofactorSign * mat->data[0][i] * determinant(mat + 1, n - 1);

        // Accumulate the determinant with the cofactor
        det += cofactor;
    }

    return det;
}
