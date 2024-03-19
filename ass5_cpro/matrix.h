#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Matrix {
    int num_rows;
    int num_cols;
    long long int** data;
} Matrix;

Matrix* create_matrix(int r, int c);
Matrix* add_matrix(Matrix* A, Matrix* B);
Matrix* mult_matrix(Matrix* A, Matrix* B);
Matrix* scalar_mult_matrix(Matrix* M,long long int s);
Matrix* transpose_matrix(Matrix* A);
long long int determinant(Matrix* M);
Matrix* destroy_matrix(Matrix* m);
void print_matrix(Matrix* m);
Matrix* read_matrix_from_file(char* file_passed);
int write_matrix_to_file(char* file_passed,Matrix* m);
void history();