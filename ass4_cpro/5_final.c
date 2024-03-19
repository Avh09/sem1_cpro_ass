#include<stdio.h>
char *func(int n,int i,char *str);
int n,count=0,flag=0;
int main(){
    scanf("%d",&n);
    char str[n+1];
    scanf("%s",str);
    for(int i=0;i<n;i++){
        if(str[i]=='"'){
            flag=1;
            count++;
            if(count%2!=0){
                continue;
            }
            else if(count%2==0){
                func(n,i,str);
                continue;
            }
            else{
                continue;
            }
        }
        else if(str[i]==',' && flag!=1){
            str[i]='*';
            continue;
        }
    }
    printf("%s",str);
}

char *func(int n,int i,char *str){
    for(int j=i+1;j<n;j++){
        if(str[j]==','){
            str[j]='*';
            if(j==n-1){
                return str;
            }
            else{
                continue;
            }
        }
        else if(str[j]=='"'){
            return str;
        }
        else{
            continue;
        }
    }

}