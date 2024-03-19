#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct Matrix {
    int        num_rows;
    int        num_cols;
    long long int** data;
} Matrix;

Matrix* create_matrix(int n, int m,int flag,int marker,int s);
Matrix* add_matrix(Matrix* A,Matrix* B);
Matrix* mult_matrix(Matrix* A,Matrix* B);
Matrix* scalar_mult_matrix(Matrix* A,int s);
Matrix* transpose_matrix(Matrix* A);
// void determinant(Matrix* A);
// void destroy_matrix(Matrix* A);

void print_matrix(Matrix* m) {
    for (int i = 0; i < m->num_rows; i++) {
        for (int j = 0; j < m->num_cols; j++) {
            printf("%lld ", m->data[i][j]);
        }
        printf("\n");
    }
}

Matrix* create_matrix(int n, int m,int flag,int marker,int s){
    if(flag == 1){
        Matrix* A = (Matrix*) malloc(sizeof(Matrix));
        A->num_rows = n;
        A->num_cols = m;
        A->data = (long long int**) calloc(n, sizeof(long long int*));
        for (int i =0; i < n; i++) {
            A->data[i] = (long long int*) calloc(m, sizeof(long long int));
            for(int j=0;j < m;j++)
            {
                scanf("%lld",&A->data[i][j]);
            }
        }
        int r,c;
        scanf("%d %d",&r,&c);
        Matrix* B = (Matrix*) malloc(sizeof(Matrix));
        B->num_rows = r;
        B->num_cols = c;
        B->data = (long long int**) calloc(r, sizeof(long long int*));
        for (int i =0; i < r; i++) {
            B->data[i] = (long long int*) calloc(c, sizeof(long long int));
            for(int j=0;j < c;j++){
                scanf("%lld",&B->data[i][j]);
            }
        }
        if(marker == 3){
            if(n!=r || m!=c){
                printf("ERROR: INVALID ARGUMENT\n");
            }
            else{
                add_matrix(A,B);
            }
        }
        else if(marker == 4){
            if(n!=r || m!=c){
                printf("ERROR: INVALID ARGUMENT\n");
            }
            else{
                mult_matrix(A,B);
            }
        }

    }
    else{
        Matrix* A = (Matrix*) malloc(sizeof(Matrix));
        A->num_rows = n;
        A->num_cols = m;
        A->data = (long long int**) calloc(n, sizeof(long long int*));
        for (int i =0; i < n; i++) {
            A->data[i] = (long long int*) calloc(m, sizeof(long long int));
            for(int j=0;j < m;j++){
                scanf("%lld",&A->data[i][j]);
            }
        }
        if(marker == 5){
            scalar_mult_matrix(A,s);
        }
        else if(marker == 6){
            transpose_matrix(A);
        }
    //     else if(marker == 7){
    //         if(n != m){
    //             printf("ERROR: INVALID ARGUMENT\n");
    //         }
    //         else{
    //             determinant(A);
    //         }
    //     }
        

    }
    //return m;
    // for(int i=0;i<r;i++){
    //     for(int j=0;j<c;j++){
    //         printf("%.1f ",m->data[i][j]);
    //     }
    //     printf("\n");
    // }
}

Matrix* add_matrix(Matrix* A,Matrix* B){
    Matrix* m = (Matrix*) malloc(sizeof(Matrix));
    m->num_rows = A->num_rows;
    m->num_cols = A->num_cols;
    m->data = (long long int**) calloc(m->num_rows, sizeof(long long int*));
    for (int i =0; i < m->num_rows; i++) {
        m->data[i] = (long long int*) calloc(m->num_cols, sizeof(long long int));
    }

    for(int i=0;i<m->num_rows;i++){
        for(int j=0;j<m->num_cols;j++){
            m->data[i][j] = A->data[i][j] + B->data[i][j];
        }
    }
    printf("\n");
    printf("%d %d\n",m->num_rows,m->num_cols);
    print_matrix(m);

}

Matrix* mult_matrix(Matrix* A,Matrix* B){
    Matrix* m = (Matrix*) malloc(sizeof(Matrix));
    m->num_rows = A->num_rows;
    m->num_cols = A->num_cols;
    m->data = (long long int**) calloc(m->num_rows, sizeof(long long int*));
    for (int i =0; i < m->num_rows; i++) {
        m->data[i] = (long long int*) calloc(m->num_cols, sizeof(long long int));
    }

    for(int i=0;i<m->num_rows;i++){
        for(int j=0;j<m->num_cols;j++){
            m->data[i][j] = A->data[i][j] * B->data[i][j];
        }
    }
    printf("\n");
    printf("%d %d\n",m->num_rows,m->num_cols);
    print_matrix(m);

}

Matrix* scalar_mult_matrix(Matrix* A,int s){
    
    Matrix* m = (Matrix*) malloc(sizeof(Matrix));
    m->num_rows = A->num_rows;
    m->num_cols = A->num_cols;
    m->data = (long long int**) calloc(m->num_rows, sizeof(long long int*));
    for (int i =0; i < m->num_rows; i++) {
        m->data[i] = (long long int*) calloc(m->num_cols, sizeof(long long int));
    }

    for(int i=0;i<m->num_rows;i++){
        for(int j=0;j<m->num_cols;j++){
            m->data[i][j] = (A->data[i][j]) * s;
        }
    }
    printf("\n");
    printf("%d %d\n",m->num_rows,m->num_cols);
    print_matrix(m);

}

Matrix* transpose_matrix(Matrix* A){
    Matrix* m = (Matrix*) malloc(sizeof(Matrix));
    m->num_rows = A->num_cols;
    m->num_cols = A->num_rows;
    m->data = (long long int**) calloc(m->num_rows, sizeof(long long int*));
    for (int i =0; i < m->num_rows; i++) {
        m->data[i] = (long long int*) calloc(m->num_cols, sizeof(long long int));
    }
    for(int i=0;i<A->num_rows;i++){
        for(int j=0;j<A->num_cols;j++){
            m->data[j][i] = (A->data[i][j]);
        }
    }
    printf("\n");
    printf("%d %d\n",m->num_rows,m->num_cols);
    print_matrix(m);
}

int main(){
    int q,integer,flag=0,marker=0,s=0;
    char operation[20];
    scanf("%d",&q);
    
    for(int i=0;i<q;i++){
        scanf("%s%d",operation,&integer);

        if(strcmp(operation,"add_matrix")==0){
            int n,m;
            scanf("%d %d",&n,&m);
            flag=1;
            marker=3;
            create_matrix(n,m,flag,marker,s);
        }
        if(strcmp(operation,"mult_matrix")==0){
            int n,m;
            scanf("%d %d",&n,&m);
            flag=1;
            marker=4;
            create_matrix(n,m,flag,marker,s);
        }
        if(strcmp(operation,"scalar_mult_matrix")==0){
            marker=5;
            int s;
            scanf("%d",&s);
            //scalar_mult_matrix(s,marker);
            int n,m;
            scanf("%d %d",&n,&m);
            create_matrix(n,m,flag,marker,s);
        }
        if(strcmp(operation,"transpose_matrix")==0){
            int n,m;
            scanf("%d %d",&n,&m);
            marker=6;
            create_matrix(n,m,flag,marker,s);
        }
        // if(strcmp(operation,"determinant")==0){
        //     int n,m;
        //     scanf("%d %d",&n,&m);
        //     marker=7;
        //     create_matrix(n,m,flag,marker);
        // }
        
    }
 
}