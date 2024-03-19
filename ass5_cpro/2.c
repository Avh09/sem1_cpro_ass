#include <stdio.h>
#include <stdlib.h>
#include<string.h>


typedef struct Matrix {
    int num_rows;
    int num_cols;
    long long int** data;
} Matrix;

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
int determinant(Matrix* M);

//int m,n; // original matrix dimensions

//int det(int B[m][n]);

int main(){
    int q,integer,s=0;
    char operation[20];
    scanf("%s%d",operation,&integer);
    //int determinant;
    //int row,column;

    // printf("Enter rows and columns\n");
    // scanf("%d%d",&m,&n);
    
    //int A[m][n];

    int n1,m1;
    scanf("%d%d",&n1,&m1);

    Matrix* A = create_matrix(n1,m1);
            for (int i =0; i < n1; i++){
                for(int j=0;j < m1;j++){
                    scanf("%lld",&A->data[i][j]);
                }

            }

    //printf("Enter matrix elements\n");

    // for(row = 0; row < m; row++)
    //     for(column = 0; column < n; column++)
    //         scanf("%d",&A[row][column]);
            
    //determinant = det(A);
    int det = determinant(A);

    printf("determinant = %d \n",det);

    return 0;
}

int determinant(Matrix* M){
    //int row_size = M->num_rows;
    //int column_size = M->num_cols;

    // if (row_size != column_size) {
    //     printf("DimensionError: Operation Not Permitted \n");
    //     exit(1);
    // }

    if (M->num_rows == 1)
        return (M->data[0][0]);

    else if (M->num_rows == 2)
        return (M->data[0][0]*M->data[1][1] - M->data[1][0]*M->data[0][1]);

    else {
        Matrix* minor = create_matrix(M->num_rows-1,M->num_cols-1);
        int row_minor, column_minor;
        int firstrow_columnindex;
        int sum = 0;

        int row,column;

        // exclude first row and current column
        for(firstrow_columnindex = 0; firstrow_columnindex < M->num_rows-1;firstrow_columnindex++){

            row_minor = 0;

            for(row = 1; row < M->num_rows; row++) {

                column_minor = 0;

                for(column = 0; column < M->num_cols-1; column++) {
                    if (column == firstrow_columnindex)
                        continue;
                    else
                        minor->data[row_minor][column_minor] = M->data[row][column];

                    column_minor++;
                }

                row_minor++;
            }

            M->num_rows = row_minor;
            M->num_cols = column_minor;

            if (firstrow_columnindex % 2 == 0){
                sum += M->data[0][firstrow_columnindex] * determinant(minor);
                printf("minor\n");
                for (int i = 0; i < M->num_rows-1; i++) {
                        for (int j = 0; j < M->num_cols-1; j++) {
                            printf("%lld ", minor->data[i][j]);
                        }
                        printf("\n");
                        }
            printf("add_sum : %d\n",sum);
            }
            else{
                sum -= M->data[0][firstrow_columnindex] * determinant(minor);
                printf("minor\n");
                for (int i = 0; i < M->num_rows-1; i++) {
                        for (int j = 0; j < M->num_cols-1; j++) {
                            printf("%lld ", minor->data[i][j]);
                        }
                        printf("\n");
                        }
            printf("sub_sum : %d\n",sum);
            }

        }

        return sum;

    }
}                                                                                                                          
