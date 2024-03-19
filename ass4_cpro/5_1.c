#include<stdio.h>
#include<string.h>
char *func(int n,int j,char *str);
int main(){
    int n,k=0,j;
    scanf("%d",&n);
    char str[1000010];
    char dup[1000010];
    scanf("%s",str);
    //int length = strlen(str);
    for(int i=0;i<n;i=j+1){
    // int i=0;
    // while(i<length){
        if(str[i]=='"'){
            //dup[k]=str[i];
            k++;
            if(k%2==0){
                func(n,j,str);
            }
            for(int j=i+1;j<(n-i-1);j++){
                if(str[j]=='"'){
                    //dup[k]=str[j];
                    k++;
                    if(k%2==0){
                        func(n,j,str);
                        //strcpy(dup,str);
                    }
                    //break;
                }
                else{
                    continue;
                }
            }
            
        }
        else{
            j=i;
            continue;
        }
        
    }
    printf("%s",str);
    //printf("%s ",dup);
}


char *func(int n,int j,char *str){
    for(int i=j+1;i<(n-j-1);i++){
        printf("%d",j);
        if(str[i]=='"'){
            printf("\n$$$\n");
            return str;
            break;
        }
        else if(str[i]==','){
            printf("\n***\n");
            str[i]='*';
            continue;
           
        }
        else{
            printf("\n^^^\n");
            continue;
           
        }
    }
}