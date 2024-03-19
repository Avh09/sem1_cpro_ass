#include<stdio.h>
int main(){
    int N,c=0,i,j,result=0;
    scanf("%d",&N);
    int arr[N];
    for(i=0;i<N;i++){
    scanf("%d",&arr[i]);
    }


    for(i=0;i<N;i++){

        for(j=i;j<N;j++){
            c = 0;
            if(arr[i]==arr[j]){
               //int k=arr[i+1];
               if(j!=i){
                c=2;
               }
                for(int k=i+1;k<j;k++){
                    if(arr[k]==arr[j-(k-i)]){
                        c++;
                    }
                }
                        if(c==j-i+1){
                            result++;
                        }

                    

                

            }

        }
        
        
    }
    

    printf("%d",result+N);
    return 0;


}