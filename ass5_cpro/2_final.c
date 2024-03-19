#include<stdio.h>
#include<string.h>
char* rev(char *S);
int main(){
    char S[1000000],J[1000000],str[1000000];
    int M,Q,L,flag=0,count=0;
    scanf("%s\n",S);
    int len = strlen(S);
    scanf("%d\n",&M);
    for(int i=0;i<M;i++){
        scanf("%d",&Q);
        if(i == M-1 && Q == 1){
            count++;
            if(count%2 == 1){
                rev(S);
            }
        }
        else if(i == M-1 && Q == 2){
            scanf("%d %s",&L,J);
            if(count%2 == 1 && L == 2){
                strcat(J,S);
                strcpy(S,J);
                rev(S);
            }
            else if(count%2 == 1 && L == 1){
                strcat(S,J);
                rev(S);
            }
            else if(count%2 == 0 && L == 1){
                strcat(J,S);
                strcpy(S,J);
            }
            else if(count%2 == 0 && L == 2){
                strcat(S,J);
            }

        }

        else if(Q == 1){
            count++;
        }
        else if(Q == 2){
            scanf("%d %s",&L,J);
            if(count%2 == 1 && L == 2){
                strcat(J,S);
                strcpy(S,J);
            }
            else if(count%2 == 1 && L == 1){
                strcat(S,J);
            }
            else if(count%2 == 0 && L == 1){
                strcat(J,S);
                strcpy(S,J);
            }
            else if(count%2 == 0 && L == 2){
                strcat(S,J);
            }
        }
    }
    printf("%s",S);
}
char* rev(char *S){
    int len = strlen(S);
    int up = 0;
    int down = len - 1;

    while (up < down) {
        // Swap characters at start and end
        char storage = S[up];
        S[up] = S[down];
        S[down] = storage;

        // Move indices towards each other
        up++;
        down--;
    }

    return S;
}