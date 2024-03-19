#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void func(char* s);

int main(){
    int N,H;
    scanf("%d %d",&N,&H);
    char S[N+1];
    char s[N+1];
    scanf("%s",S);
    // if(strcmp(S,"abab") == 0){
    //     //printf("---\n");
    //     printf("0");
    // }
    //else{
        if(H == 1){
        func(S);
        }
        else{
            int i=0,index=0;
            while(i<N-1){
                if (i+H > N){
                    break;
                }
                for(int j=i+1;j<N;j++){
                    if(S[i] != S[j]){
                       i=j;
                        break;
                    }
                    else if(S[i] == S[j] && j == i+H-1){
                        s[index] = S[i];
                        index++;
                        i = i+H;
                        break;
                    }
                }
            }
            func(s);
        }

    //}
    
}

void func(char* s){
    //printf("flag : 6\n");
    int len = strlen(s);
   
    //printf("len : %d\n",len);
    if(len == 0){
        printf("0");
    }
    else if(len == 1){
        printf("1");
    }
    else{
        int compare(const void* x_void,const void* y_void){
            char x = *(char*)x_void;
            char y = *(char*)y_void;
            return x-y;
        }
        qsort(s,len,sizeof(char),compare);
        
        int max=0,count=1;
        for(int i=0;i<len-1;i++){
            if(s[i] == s[i+1]){
                count++;

            }
            else if(s[i] != s[i+1]){
                if(count>max){
                    max = count;
                }
                count = 1;
            }
        }
        if(count>max){
            max = count;
        }
        printf("%d",max);
    }
}






