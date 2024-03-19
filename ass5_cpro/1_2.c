#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char S[200000],store[200000],total[200000];
int compare(const void* numA, const void* numB){
    const int* num1 = (const int*)numA;
    const int* num2 = (const int*)numB;

    if (*num1 > *num2) {
        return 1;
    }
    else if(*num1 == *num2){
        return 0;
    }
    else{
        return -1;
    }
}

int main(){
    int N,H,count,flag=0;
    scanf("%d %d",&N,&H);
    scanf("%s",S);
    for(int i=0;i<(N/H);i+=2){
        printf("______ok\n");
        for(int j=i+1;j<(H-1);j++){
            if(S[i] != S[j]){
                printf("^^^^^^\n");
                flag=0;
                break;
            }
            else if(i == (N/H)-1){
                if(S[i] == S[j]){
                    printf("#####\n");
                    flag=1;
                    break;
                }
                else{
                    printf("$$$$\n");
                    flag=0;
                    break;
                }

            }
            else if(S[i] == S[j]){
                printf("*****\n");
                continue;
            }
        }
        if(flag == 1){
            for(int j=0;j<(H-1);j++){
                printf("----\n");
                store[j]=S[i];
                printf("%c\n",store[j]);
            }
        }
    }
    int len = strlen(store);
    for(int k=0;k<len;k++){
        for(int g=k+1;g<(len);g++){
            int count=0;
            if(store[k]==store[g]);
            count++;
        }
        total[k]=count;
        printf("%d\n",total[k]);
    }
    //qsort(total, len, sizeof(int), compare);
    //printf("%d",total[len-1]);
}