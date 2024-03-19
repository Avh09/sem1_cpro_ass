#include<stdio.h>
#include<stdlib.h>
int func(int *arr,int m);

int main(){
    int m,n;
    scanf("%d",&n);
    int fin[n];

    
    for(int i=0;i< n;i++){
        int a=0;
        scanf("%d",&m);
        
        int arr[m];
        for(int j=0;j<m;j++){
            scanf("%d",&arr[j]);
        }
        a=func(arr,m);
        
        fin[i]=a;

    }
    for(int j=0;j< n;j++){
    printf("%d\n",fin[j]);
    }

    return 0;
}


int func(int *arr,int m){

int max=0;
int dp[m];

for(int z=m-1;z>=0;z--){
    dp[z] = 0;
    int a=0,i=z;
    while(i<m){
        if(dp[i] != 0){
            
            a=a+dp[i];           
            break;
        }
        else{

            a=a+arr[i];
            i=i+arr[i];
        }
    }
    dp[z] = a;
    // printf("%d ",dp[z]);
    
    if(a>=max){
        max=a;
    }
}

    return max;
     
}