#include "matrix.h"
int main(){
    int q,integer,s=0;
    char operation[20];
    scanf("%d\n",&q); 
    
    for(int i=0;i<q;i++){
        scanf("%s%d",operation,&integer);
        //char* fgets(char* str,int n,stdin);

        if(strcmp(operation,"add_matrix")==0){
            if(integer == 0){
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
            else if(integer == 1){
                char file1[50];
                char file2[50];
                char output[50];
                scanf("%s",file1);
                scanf("%s",file2);
                scanf("%s",output);
                Matrix* A = read_matrix_from_file(file1);
                Matrix* B = read_matrix_from_file(file2);
                Matrix* m = add_matrix(A,B);
                int matrix = write_matrix_to_file(output,m);
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
            else if(integer == 1){
                char file1[50];
                char file2[50];
                char output[50];
                scanf("%s",file1);
                scanf("%s",file2);
                scanf("%s",output);
                Matrix* A = read_matrix_from_file(file1);
                Matrix* B = read_matrix_from_file(file2);
                Matrix* m = mult_matrix(A,B);
                write_matrix_to_file(output,m);
            }
        }

        else if(strcmp(operation,"scalar_mult_matrix")==0){
            if(integer == 0){
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
            else if(integer == 1){
                char file1[50];
                char output[50];
                scanf("%s",file1);
                scanf("%s",output);
                Matrix* A = read_matrix_from_file(file1);
                Matrix* m = scalar_mult_matrix(A,s);
                write_matrix_to_file(output,m);

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
            }
            else if(integer == 1){
                char file1[50];
                char output[50];
                scanf("%s",file1);
                scanf("%s",output);
                Matrix* A = read_matrix_from_file(file1);
                Matrix* m = transpose_matrix(A);
                write_matrix_to_file(output,m);

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
                if(det == -1){
                    printf("ERROR: INVALID ARGUMENT");

                }
                else{
                    printf("%lld",det);
                }
            }
            else if(integer == 1){
                char file1[50];;
                scanf("%s",file1);
                Matrix* A = read_matrix_from_file(file1);
                long long int det = determinant(A);
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
