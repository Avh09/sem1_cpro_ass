#include<stdio.h>
#include<string.h>
int N,H,max=0,flag=0;
char S[200000],s[200000];
void func(char* s);
int main(){
    scanf("%d %d",&N,&H);
    scanf("%s",S);
    if(H == 1){
        func(S);
    }

    //for(int i=0;i<N;i++){
    int i=0,index=0;
    while(i<N){
        for(int j=i+1;j<i+H;j++){
            if(S[i] == S[j] && j == i+H-1){
                s[index] = S[i];
                index++;
                i = i+H;
            }
            else if(S[i] == S[j] && j != i+H-1){
                continue;
            }
            else if(S[i] != S[j]){
                i++;
                break;
            }
        }
    }
    func(s);
}
void func(char* s){
    // int max=0,count;
    int len = strlen(s);
    printf("s : %s\n",s);
    
    int count = 0,flag=1;

    for (int i=0; i<len; i++)
    {
        //printf("%d..\n",i);
        int cur_count = 1;
        for (int j=i+1; j<len; j++)
        {
            //printf("i : %d, %c\n",i,s[i]);
            //printf("j : %d, %c\n",j,s[j]);
            if (s[i] == s[j]){
                //printf("((()))");
                cur_count++;
                //break;
            }
            else if(s[i] != s[j]){
                if (cur_count >= count){
                    count = cur_count;
                }
            }
           
        }
        if(flag==0)
        break;

        
    }
    printf("%d",count);

}


