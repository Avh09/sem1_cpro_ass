#include<stdio.h>
int main(){
    int n,i,flag;
    scanf("%d",&n);
    int arr[n];
    for(int i=2;i<=n;i++){
        flag=0;
        for(int j=2;j<=i;j++){
            if(i!=j && i%j==0){
                flag=1;
                break;
            }
        }
        if(flag!=1){
            printf("%d ",i);

        }
    }
    
}
