#include "matrix.h"
int main(){
    int q,integer,s=0,flag=0;
    char operation[20];
    scanf("%d\n",&q); 
    
    FILE *file;
    file = fopen("mx_history", "a");
    if (file == NULL) {
        printf("ERROR: INVALID ARGUMENT\n");
    }
    fclose(file);

    for(int i=0;i<q;i++){
        scanf("%s",operation);
        file = fopen("mx_history", "a");
        fprintf(file, "LOG::%s ", operation);
        if(strcmp(operation,"history") != 0){
            scanf("%d",&integer);
            fprintf(file, "%d", integer);
        }
        fprintf(file,"\n");
        fclose(file);
        if(strcmp(operation,"history")==0){
            history();
        }
        else if(strcmp(operation,"add_matrix")==0){
            if(integer == 0){
                int n1,m1;
                scanf("%d%d",&n1,&m1);
                Matrix* A = create_matrix(n1,m1);
                for (int i =0; i < n1; i++){
                    for(int j=0;j < m1;j++){
                        scanf("%lld",&A->data[i][j]);
                    }
                }
                int n2,m2;
                scanf("%d%d",&n2,&m2);
                Matrix* B = create_matrix(n2,m2);
                for (int i =0; i < n2; i++){
                    for(int j=0;j < m2;j++){
                        scanf("%lld",&B->data[i][j]);
                    }
                }
                Matrix* m = add_matrix(A,B);
                if(m == NULL){
                    printf("ERROR: INVALID ARGUMENT\n");
                }
                else{
                    print_matrix(m);
                    destroy_matrix(A);
                    destroy_matrix(B);
                    destroy_matrix(m);
                }
            }
            else if(integer == 1){
                char file_name1[50];
                char file_name2[50];
                char output[50];
                scanf("%s",file_name1);
                scanf("%s",file_name2);
                scanf("%s",output);
                Matrix* A = read_matrix_from_file(file_name1);
                if(A == NULL){
                    printf("ERROR: INVALID ARGUMENT\n");
                }
                else{
                    Matrix* B = read_matrix_from_file(file_name2);
                    if(B == NULL){
                        printf("ERROR: INVALID ARGUMENT\n");
                    }
                    else{
                            Matrix* m = add_matrix(A,B);
                            if(m == NULL){
                                printf("ERROR: INVALID ARGUMENT\n");
                            }
                            else{
                                int matrix = write_matrix_to_file(output,m);
                                destroy_matrix(m);
                            }
                            
                        destroy_matrix(B);
                    }
                    destroy_matrix(A);
                }
            }
        }
        else if(strcmp(operation,"mult_matrix")==0){
            if(integer == 0){
                int n1,m1;
                scanf("%d%d",&n1,&m1);
                Matrix* A = create_matrix(n1,m1);
                for (int i =0; i < n1; i++){
                    for(int j=0;j < m1;j++){
                        scanf("%lld",&A->data[i][j]);
                    }
                }
                int n2,m2;
                scanf("%d%d",&n2,&m2);
                Matrix* B = create_matrix(n2,m2);
                for (int i =0; i < n2; i++){
                    for(int j=0;j < m2;j++){
                        scanf("%lld",&B->data[i][j]);
                    }
                }
                Matrix* m = mult_matrix(A,B);
                if(m == NULL){
                    printf("ERROR: INVALID ARGUMENT\n");
                }
                else{
                    print_matrix(m);
                    destroy_matrix(A);
                    destroy_matrix(B);
                    destroy_matrix(m);
                }
            }
            else if(integer == 1){
                char file_name1[50];
                char file_name2[50];
                char output[50];
                scanf("%s",file_name1);
                scanf("%s",file_name2);
                scanf("%s",output);
                Matrix* A = read_matrix_from_file(file_name1);
                if(A == NULL){
                    printf("ERROR: INVALID ARGUMENT\n");
                }
                else{
                    Matrix* B = read_matrix_from_file(file_name2);
                    if(B == NULL){
                        printf("ERROR: INVALID ARGUMENT\n");
                    }
                    else{
                        Matrix* m = mult_matrix(A,B);
                        if(m == NULL){
                            printf("ERROR: INVALID ARGUMENT\n");
                        }
                        else{
                            write_matrix_to_file(output,m);
                            destroy_matrix(m);
                        }
                        destroy_matrix(B);
                    }
                    destroy_matrix(A);
                }

            }
        }
        else if(strcmp(operation,"scalar_mult_matrix")==0){
            long long int s;
            scanf("%lld",&s);
            if(integer == 0){
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
                destroy_matrix(A);
                destroy_matrix(m);
            }
            else if(integer == 1){
                char file_name[50];
                char output[50];
                scanf("%s",file_name);
                scanf("%s",output);
                Matrix* A = read_matrix_from_file(file_name);
                if(A == NULL){
                    printf("ERROR: INVALID ARGUMENT\n");
                }
                else{
                    Matrix* m = scalar_mult_matrix(A,s);
                    write_matrix_to_file(output,m);
                    destroy_matrix(m);
                    destroy_matrix(A);
                }
            }
        }
        else if(strcmp(operation,"transpose_matrix")==0){
            if(integer == 0){
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
                destroy_matrix(A);
                destroy_matrix(m);
            }
            else if(integer == 1){
                char file_name[50];
                char output[50];
                scanf("%s",file_name);
                scanf("%s",output);
                Matrix* A = read_matrix_from_file(file_name);
                if(A == NULL){
                    printf("ERROR: INVALID ARGUMENT\n");
                }
                else{
                    Matrix* m = transpose_matrix(A);
                    write_matrix_to_file(output,m);
                    destroy_matrix(A);
                    destroy_matrix(m);
                }
              
            }
        }
        else if(strcmp(operation,"determinant")==0){
            if(integer == 0){
                int n1,m1;
                scanf("%d%d",&n1,&m1);
                Matrix* A = create_matrix(n1,m1);
                for (int i =0; i < n1; i++){
                    for(int j=0;j < m1;j++){
                        scanf("%lld",&A->data[i][j]);
                    }
                }
                long long int det = determinant(A);
                destroy_matrix(A);
                if(n1 == m1){
                    printf("%lld\n",det);
                }
            }
            else if(integer == 1){
                char file_name[50];
                scanf("%s",file_name);
                
                Matrix* A = read_matrix_from_file(file_name);
                if(A == NULL){
                    printf("ERROR: INVALID ARGUMENT\n");
                }
                else{
                    long long int det = determinant(A);
                    if(A->num_rows == A->num_cols){
                        printf("%lld\n",det);
                    }
                    destroy_matrix(A);
                }
            }
        }   
    }
}

