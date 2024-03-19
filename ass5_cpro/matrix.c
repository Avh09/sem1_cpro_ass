#include "matrix.h"

Matrix* read_matrix_from_file(char file_passed[]){
  
    int rows, cols;
    FILE *file = fopen(file_passed, "r");

    if (file == NULL){
        return NULL;
    }
    else{
        // Read the dimensions of the matrix
        fscanf(file, "%d %d", &rows, &cols);

        Matrix* M = create_matrix(rows,cols);

        // Read the matrix elements
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                fscanf(file, "%lld", &M->data[i][j]);
            }
        }
        fclose(file);
        return M;
    }
	
}
int write_matrix_to_file(char* file_passed,Matrix* m){
    FILE *file = fopen(file_passed, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
    }
    else{
    // Write dimensions of the matrix to the file
        fprint(file, "%d %d\n", m->num_rows, m->num_cols);

    // Write the matrix elements to the file
        for (int i = 0; i < m->num_rows; ++i) {
            for (int j = 0; j < m->num_cols; ++j) {
                fprintf(file, "%lld ", m->data[i][j]);
            }
        fprintf(file, "\n");
        }
    }
    fclose(file);

}
Matrix* create_matrix(int r, int c){
    Matrix* m = (Matrix*) malloc(sizeof(Matrix));
    m->num_rows = r;
    m->num_cols = c;
    m->data = (long long int**) calloc(r, sizeof(long long int*));
    for (int i =0; i < r; i++) {
        m->data[i] = (long long int*) calloc(c, sizeof(long long int));
    }
    return m;
}
Matrix* add_matrix(Matrix* A, Matrix* B){
    if(A->num_rows != B->num_rows || A->num_cols != B->num_cols){
        return NULL;
    }
    else{
        Matrix* m = create_matrix(A->num_rows,A->num_cols);
        for(int i=0;i<A->num_rows;i++){
            for(int j=0;j<A->num_cols;j++){
                m->data[i][j] = A->data[i][j] + B->data[i][j];
            }
        }
        return m;

    }
}
Matrix* mult_matrix(Matrix* A, Matrix* B){
    if(A->num_cols != B->num_rows){
        return NULL;
    }
    else{
        Matrix* m = create_matrix(A->num_rows,B->num_cols);

        for(int i=0;i<A->num_rows;i++){
            for(int j=0;j<B->num_cols;j++){
                for(int k=0;k<B->num_rows;k++){
                    m->data[i][j] += A->data[i][k] * B->data[k][j];
                }
            }
        }
        return m;
    }

}
Matrix* scalar_mult_matrix(Matrix* M,long long int s){
    Matrix* m = create_matrix(M->num_rows,M->num_cols);
    for(int i=0;i<M->num_rows;i++){
        for(int j=0;j<M->num_cols;j++){
            m->data[i][j] = M->data[i][j] * s;
        }
    }
    return m;
}
Matrix* transpose_matrix(Matrix* A){
    Matrix* m = create_matrix(A->num_cols,A->num_rows);
    for(int i=0;i<A->num_rows;i++){
        for(int j=0;j<A->num_cols;j++){
            m->data[j][i] = A->data[i][j];
        }
    }
    return m;

}
long long int determinant(Matrix* mat){
    if(mat->num_rows != mat->num_cols){
        printf("ERROR: INVALID ARGUMENT\n");
        return -1;
    }

    if (mat->num_rows == 1) {
        return mat->data[0][0];
    }

    if (mat->num_rows == 2) {
        return mat->data[0][0] * mat->data[1][1] - mat->data[0][1] * mat->data[1][0];
    }

    long long int det = 0;

    for (int i = 0; i < mat->num_rows; ++i) {
        // Calculate the cofactor
        int cofactorSign = (i % 2 == 0) ? 1 : -1;
        Matrix* submatrix = create_matrix(mat->num_rows - 1,mat->num_cols - 1);
        submatrix->num_rows = mat->num_rows - 1;
        submatrix->num_cols = mat->num_cols - 1;

        for (int j = 1; j < mat->num_rows; ++j) {
            int submatrixCol = 0;
            for (int k = 0; k < mat->num_cols; ++k) {
                if (k != i) {
                    submatrix->data[j - 1][submatrixCol] = mat->data[j][k];
                    submatrixCol++;
                }
            }
        }

        // Accumulate the determinant with the cofactor
        det += cofactorSign * mat->data[0][i] * determinant(submatrix);
        destroy_matrix(submatrix);
    }

    return det;
}   
Matrix* destroy_matrix(Matrix* m){
    for (int i =0; i < m->num_rows; i++){
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}
void print_matrix(Matrix* m){
    printf("%d %d\n", m->num_rows, m->num_cols);
    for (int i = 0; i < m->num_rows; i++) {
        for (int j = 0; j < m->num_cols; j++) {
            printf("%lld ", m->data[i][j]);
        }
        printf("\n");
    }
}
void history(){
    FILE* fptr;
        char c = '\0';
        fptr = fopen("mx_history","r");
        if(fptr == NULL){
            printf("ERROR: INVALID ARGUMENT");
        } 
        else{
            while(c != EOF){
                c = fgetc(fptr);
                if (c != EOF){
                    printf("%c",c);
                }
            }
        }
}
