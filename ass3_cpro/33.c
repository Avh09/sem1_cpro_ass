#include<stdio.h>
#include<string.h>
char func(char *str,char x,int k, int n);
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int q=0;
    char str[n];
    scanf("%s",str);
    int i=1;
    while(i<=n){
        char x=str[i];
        int q=str[i]-'a';
        if(q>k){
            func(str,x,k,n);
            i++;
            break;
        }

    }
    // for(int i=n;i>1;i--){
    //     str[i]='a';
    // }
    printf("%s",str);
    return 0;
}

char func(char *str,char x,int k,int n){
    int i;
    for(int i=1;i<=n;i++){
        str[i]='a';
        for(int j=1;j<=n;j++){
            
            if(str[i]-x==k){
            return str[i];
            ///break;
            }
            else{
                str[i]++;
            }

        }
        
    } return str[i];
}
