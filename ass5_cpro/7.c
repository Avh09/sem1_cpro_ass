#include <stdio.h>
#include <stdlib.h>

//#define MAX_SIZE 10

// Define a struct for the matrix
typedef struct Matrix {
    int rows;
    int cols;
    int** data;
}Matrix;

Matrix* create_matrix(int r, int c){
    Matrix* m = (Matrix*) malloc(sizeof(Matrix));
    m->rows = r;
    m->cols = c;
    m->data = (int**) calloc(r, sizeof(int*));
    for (int i =0; i < r; i++) {
        m->data[i] = (int*) calloc(c, sizeof(int));
    }
    return m;
}

// Function to calculate the determinant of a matrix
double determinant(Matrix* mat);

// Recursive helper function
double determinantRecursive(Matrix* mat);

int main() {
    
    int r,c;
    printf("Enter the number of rows of the square matrix: ");
    scanf("%d %d", &r,&c);
    Matrix* mat = create_matrix(r,c);
    //mat.cols = mat.rows;

    // Input the matrix elements
    printf("Enter the elements of the matrix:\n");

    for (int i = 0; i < mat->rows; ++i) {
        for (int j = 0; j < mat->cols; ++j) {
            printf("Enter element mat->data[%d][%d]: ", i, j);
            scanf("%d", &mat->data[i][j]);
        }
    }

    // Calculate and display the determinant
    double det = determinant(mat);
    printf("Determinant: %lf\n", det);

    return 0;
}

// Function to calculate determinant of a matrix
double determinant(Matrix* mat) {
   
    if (mat->rows == 1) {
        return mat->data[0][0];
    }

    if (mat->rows == 2) {
        return mat->data[0][0] * mat->data[1][1] - mat->data[0][1] * mat->data[1][0];
    }

    double det = 0;

    for (int i = 0; i < mat->rows; ++i) {
        // Calculate the cofactor
        int cofactorSign = (i % 2 == 0) ? 1 : -1;
        Matrix* submatrix = create_matrix(mat->rows - 1,mat->cols - 1);
        submatrix->rows = mat->rows - 1;
        submatrix->cols = mat->cols - 1;

        for (int j = 1; j < mat->rows; ++j) {
            int submatrixCol = 0;
            for (int k = 0; k < mat->cols; ++k) {
                if (k != i) {
                    submatrix->data[j - 1][submatrixCol] = mat->data[j][k];
                    submatrixCol++;
                }
            }
        }

        // Accumulate the determinant with the cofactor
        det += cofactorSign * mat->data[0][i] * determinant(submatrix);
    }

    return det;
}
