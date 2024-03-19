#include<stdio.h>
#include<string.h>
char* rev(char *S);
int main(){
    char S[100000],J;
    int M,Q,L;
    scanf("%s\n",S);
    int len = strlen(S);
    scanf("%d\n",&M);
    for(int i=0;i<M;i++){
        scanf("%d",&Q);
        printf("Q = %d\n",Q);
        if(Q == 2){
            scanf("%d %c",&L,&J);
        }
    }
    printf("S = %s\n",S);
    printf("M = %d\n",M);
    printf("Q = %d\n",Q);
    printf("S = %s\n",S);

}