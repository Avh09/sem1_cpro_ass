#include<stdio.h>
#include<string.h>
int N,H,ind=0,max=0,flag=0;
char S[200000],s[200000];
void func(char* s);
int main(){
    scanf("%d %d",&N,&H);
    scanf("%s",S);
    if(H == 1){
        flag = 1;
        //strcpy(s,S);
        func(S);

    }
    else{
    for(int i=0;i<N;i+=H){
        for(int j=(i+1);j<(i+H);j++){
            if(S[i]!=S[j]){
                flag=0;
                break;

            }
            else if(j==(i+H-1) && S[i]==S[j]){
                s[ind] = S[i];
                //printf("s : %s\n",s);
                //flag=1;
                ind++;
                break;
            }
            else if(j!=(i+H-1) && S[i]==S[j]){
                
                continue;
            }

        }

    }
    func(s);
    printf("s : %s\n",s);
    }
}
    void func(char* s){
    int len = strlen(s);
    //flag = 1;
    // for(int ind=0;ind<len;ind++){
    //     int count=0;
    //     for(int k=(ind+1);k<(len-1);k++){
    //         if(s[ind] == s[k]){
    //             count++;
    //         }
    //     }
    //     if(count > max){
    //         max = count;
    //     }
    // }
    // if(flag == 1){
    //     printf("%d",max+1);
    // }
    // if(flag == 0){
    //     printf("%d",max);
    // }

    for(int i=0;i<len;i++){
        //printf("----\n");
        int count=0;
        for(int j=i+1;j<len;j++){
            //printf("***\n");
            if(S[i] == S[j]){
                flag = 2;
                count++;
                //printf("count : %d\n",count);
            }
        }
        if(count > max){
            max = count;
        }
    }
    if(flag == 1 && flag != 2){
        max = 1;
    }
    // else if(flag != 1 && flag != 2){
    //     max = 0;
    // }
    printf("%d",max);
    }
