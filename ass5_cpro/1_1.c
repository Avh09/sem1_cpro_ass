#include<stdio.h>

void func(char *S,int ind,int N,int H);

int N,H,count=0;
char S[200000],s[200000];

int main(){
    scanf("%d %d",&N,&H);
    scanf("%s",S);
    for(int ind=0;ind<(N/H);ind++){
        printf("----\n");
        func(S,ind,N,H);
    }

}

void func(char *S,int ind,int N,int H){
    int flag=0;
    printf("***\n");
    for(int i=0;i<H;i++){
        printf("$$$$$\n");
        s[i] = S[i];

    }
    for(int k=0;k<H;k++){
        printf("_____\n");
        if(flag==1){
            printf("&&&&&\n");
            break;
        }
        for(int j=k+1;j<(H-1);j++){
            printf("#####______\n");
            if(s[k] != s[j]){
                printf("******\n");
                flag=1;
                break;
            }
            
        }

        
    }
    if(flag==0){
        printf("**----$$$$$\n");
        count++;
    }
    if(ind == (N/H)-1){
        printf("**----\n");
        printf("%d",count);
    }
}