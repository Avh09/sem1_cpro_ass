#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Define a struct for the matrix
typedef struct Matrix {
    int** data;
    int num_rows;
    int num_cols;
} Matrix;

// Function prototypes
double determinant(Matrix* mat);
//Matrix min(Matrix mat, int row, int col);

int main() {
    Matrix* mat;

    printf("Enter the size of the square matrix (n): ");
    scanf("%d", &mat->num_rows);

    // Input the matrix elements
    printf("Enter the elements of the matrix:\n");

    for (int i = 0; i < mat->num_rows; ++i) {
        for (int j = 0; j < mat->num_rows; ++j) {
            printf("Enter element mat->data[%d][%d]: ", i, j);
            scanf("%d", &mat->data[i][j]);
        }
    }

    // Calculate and display the determinant
    double det = determinant(mat);
    printf("Determinant: %lf\n", det);

    return 0;
}

// Recursive function to calculate determinant of a matrix
double determinant(Matrix* mat) {
    int sign;
    if (mat->num_rows == 1) {
        return mat->data[0][0];
    }

    if (mat->num_rows == 2) {
        return mat->data[0][0] * mat->data[1][1] - mat->data[0][1] * mat->data[1][0];
    }

    double det = 0;

    //for (int i = 0; i < mat->num_rows; ++i) {
        // Calculate the cofactor
        //int cofactorSign = (i % 2 == 0) ? 1 : -1;
        

        
        for (int i = 0, sub_i = 0; i < mat->num_rows; ++i) {

            Matrix* min;
            min->num_rows = mat->num_rows - 1;
            min->num_cols = mat->num_cols - 1;
            int row = 0;
            int col = i;
            if (i == row) {
                continue; // Skip the specified row
            }

            for (int j = 0, sub_j = 0; j < mat->num_rows; ++j) {
                if (j == col) {
                    continue; // Skip the specified column
                }

                min->data[sub_i][sub_j] = mat->data[i][j];
                ++sub_j;
            }

            ++sub_i;

            if(i%2 == 0){
                sign = 1;
            }
            else if(i%2 != 0){
                sign = -1;
            }

            double cofactor = sign * mat->data[0][i] * determinant(min);
            det += cofactor;

        }
  

    return det;
}



