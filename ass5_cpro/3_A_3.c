#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
    // // if(M->num_rows != M->num_cols){
    // //     return -1;
    // // }
    // //else{
    //     int row_num = M->num_rows;
    //     int col_num = M->num_cols;

    //     if(row_num != col_num){
    //         return -1;
    //     }

    //     else if (row_num == 1)
    //         return (M->data[0][0]);

    //     else if (row_num == 2)
    //         return (M->data[0][0]*M->data[1][1] - M->data[1][0]*M->data[0][1]);

    //     else{
    //         Matrix* minor = create_matrix(row_num-1,col_num-1);
    //         int row_minor, column_minor;
    //         long long int sum = 0;
           

    //     // exclude first row and current column
    //         for(int toprow_col = 0; toprow_col < row_num;toprow_col++){
    //             row_minor = 0;
    //                 for(int row = 1; row < row_num; row++){
    //                     column_minor = 0;
    //                     for(int column = 0; column < col_num; column++){
    //                         if(column == toprow_col) 
    //                             continue;
                        
    //                         else
    //                             //minor[row_minor][column_minor] = B[row][column];
    //                             //Matrix* minor = create_matrix(row_minor,column_minor);
    //                             minor->data[row_minor][column_minor] = M->data[row][column];
                            
    //                         column_minor++;
    //                     }
    //                     row_minor++;
    //                 }

    //             M->num_rows = row_minor;
    //             M->num_cols = column_minor;

    //             if (toprow_col % 2 == 0){
    //                 sum += M->data[0][toprow_col] * determinant(minor);
    //                 for (int i = 0; i < minor->num_rows; i++) {
    //                     for (int j = 0; j < minor->num_cols; j++) {
    //                         printf("%lld ", minor->data[i][j]);
    //                     }
    //                     printf("\n");
    //                     }

                
    //             printf("add_sum : %lld\n",sum);
    //             }
                
    //             else{
    //                 sum -= M->data[0][toprow_col] * determinant(minor);
    //                 for (int i = 0; i < minor->num_rows; i++) {
    //                     for (int j = 0; j < minor->num_cols; j++) {
    //                         printf("%lld ", minor->data[i][j]);
    //                     }
    //                     printf("\n");
    //                     }
    //             printf("sub_sum : %lld\n",sum);
    //             }
                
    //         }
    //         return sum;
    //     }
    //}

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
    }

    return det;
}   

Matrix* destroy_matrix(Matrix* m){
    for (int i =0; i < m->num_rows; i++){
        free(m->data[i]);
    }
    free(m->data);
    free(m);
    printf("DONE\n");
    print_matrix(m);
}
int main(){
    int q,integer,s=0;
    char operation[20];
    scanf("%d\n",&q); 
    
    for(int i=0;i<q;i++){
        scanf("%s%d",operation,&integer);

        if(strcmp(operation,"add_matrix")==0){
            int n1,m1;
            scanf("%d%d",&n1,&m1);
            Matrix* A = create_matrix(n1,m1);
            for (int i =0; i < n1; i++){
                for(int j=0;j < m1;j++){
                    scanf("%lld",&A->data[i][j]);
                }

            }
            //printf("&&&&\n");
            
            int n2,m2;
            scanf("%d%d",&n2,&m2);
            Matrix* B = create_matrix(n2,m2);
            for (int i =0; i < n2; i++){
                for(int j=0;j < m2;j++){
                    scanf("%lld",&B->data[i][j]);
                }

            }
            //printf("****\n");
            Matrix* m = add_matrix(A,B);
            if(m == NULL){
                printf("ERROR: INVALID ARGUMENT");
            }
            else{
                print_matrix(m);
            }
        }

        else if(strcmp(operation,"mult_matrix")==0){
            int n1,m1;
            scanf("%d%d",&n1,&m1);
            Matrix* A = create_matrix(n1,m1);
            for (int i =0; i < n1; i++){
                for(int j=0;j < m1;j++){
                    scanf("%lld",&A->data[i][j]);
                }

            }
            //printf("****\n");
            
            int n2,m2;
            scanf("%d%d",&n2,&m2);
            Matrix* B = create_matrix(n2,m2);
            for (int i =0; i < n2; i++){
                for(int j=0;j < m2;j++){
                    scanf("%lld",&B->data[i][j]);
                }

            }
            //printf("&&&&\n");
            Matrix* m = mult_matrix(A,B);
            if(m == NULL){
                printf("ERROR: INVALID ARGUMENT");
            }
            else{
                print_matrix(m);
            }
        }

        else if(strcmp(operation,"scalar_mult_matrix")==0){
            long long int s;
            scanf("%lld",&s);
            int n1,m1;
            scanf("%d%d",&n1,&m1);
            Matrix* A = create_matrix(n1,m1);
            for (int i =0; i < n1; i++){
                for(int j=0;j < m1;j++){
                    scanf("%lld",&A->data[i][j]);
                }
            }
            Matrix* m = scalar_mult_matrix(A,s);
            print_matrix(m);
        }

        else if(strcmp(operation,"transpose_matrix")==0){
            int n1,m1;
            scanf("%d%d",&n1,&m1);
            Matrix* A = create_matrix(n1,m1);
            for (int i =0; i < n1; i++){
                for(int j=0;j < m1;j++){
                    scanf("%lld",&A->data[i][j]);
                }

            }
            Matrix* m = transpose_matrix(A);
            print_matrix(m);
        }

        else if(strcmp(operation,"determinant")==0){
            int n1,m1;
            scanf("%d%d",&n1,&m1);
            Matrix* A = create_matrix(n1,m1);
            for (int i =0; i < n1; i++){
                for(int j=0;j < m1;j++){
                    scanf("%lld",&A->data[i][j]);
                }

            }
             long long int det = determinant(A);
            if(det == -1){
                printf("ERROR: INVALID ARGUMENT");

            }
            else{
                printf("%lld",det);
            }

        }

        else if(strcmp(operation,"destroy_matrix")==0){
            int n1,m1;
            scanf("%d%d",&n1,&m1);
            Matrix* A = create_matrix(n1,m1);
            for (int i =0; i < n1; i++){
                for(int j=0;j < m1;j++){
                    scanf("%lld",&A->data[i][j]);
                }

            }
            destroy_matrix(A);
            printf("DONE\n");

        }


    }
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