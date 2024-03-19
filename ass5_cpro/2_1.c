#include<stdio.h>
#include<string.h>
char* rev(char *S);
int main(){
    char S[1000000],J[1000000],str[1000000];
    int M,Q,L,flag=0;
    scanf("%s\n",S);
    int len = strlen(S);
    scanf("%d\n",&M);
    for(int i=0;i<M;i++){
        scanf("%d",&Q);
        if(Q == 2){
            if(flag != 0){
                if(flag%2 != 0){
                flag=0;
                rev(S);
                }
            }
            scanf("%d %s",&L,J);
            
            if(L == 1){
                strcat(J,S);
                strcpy(S,J);
                
            }
            else if(L == 2){
                strcat(S,J);
                
            }
        }
        else if(Q == 1 && M == 1){
            rev(S);
        }
        
        else if(Q == 1 && i != (M-1)){
            flag++;
        }
        else if(Q == 1 && i == (M-1)){
            if(flag == 0){
                // if(flag%2 != 0){
                rev(S);
                //}
            }

        }
       
    }
    printf("%s",S);
}

// char* rev(char *S){
//     int j,count=0;
//     char rev[1000000];
//     while (S[count] != '\0'){
//         count++;
//     }
//     j = count - 1;

//     //swapping
//     for (int i = 0; i < count; i++){
//         rev[i] = S[j];
//         j--;
//     }
//     strcpy(S,rev);
//     return S;
   
// }

char* rev(char *S) {
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

