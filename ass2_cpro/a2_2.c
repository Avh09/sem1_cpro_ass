#include<stdio.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int j,N,A,D;
    scanf("%d",&N);
    int arr[N+1][N+1];
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){

            scanf("%d",&arr[i][j]);
        } 

    }



    
    scanf("%d",&D);
    
    int ru=arr[1][N];
    int rl=arr[N][N];
    int ll=arr[N][1];
    int lu=arr[1][1];
    int a=arr[2][1];
    int b=arr[N-1][N];
    int c=arr[N-1][1];
    int d=arr[2][N];

    if(D==1){

        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){

                if(i==1){
                    
                    arr[i][N-j+1]=arr[i][N-j];
                    //arr[i][2]=lu;
                }

                else if(i==N){
                    
                    arr[i][j]=arr[i][j+1];
                    
                }


                else if(j==1 && i!=N){
                    
                    arr[i][j]=arr[i+1][j];
                }
                
                   
                else if(j==N && i!=1){
                    
                    arr[N-i+1][j]=arr[N-i][j];
                
                }
            } 
        }
     arr[N-1][1]=ll;
     arr[1][2]=lu;
     arr[2][N]=ru;
     arr[1][1]=a;
     arr[N][N]=b;
     

    }
     
     
     if(D==0){

        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){

                if(i==1){
                    arr[i][j]=arr[i][j+1];
                }

                else if(i==N){
                    arr[i][N-j+1]=arr[i][N-j];
                }
        
                else if(j==1 && i!=1){
                    arr[N-i+1][j]=arr[N-i][j];
                }

                else if(j==N && i!=N){
                    arr[i][j]=arr[i+1][j];
                }

            
            }
        
        }
        
     arr[2][1]=lu;
     arr[N-1][N]=rl;
     arr[N][1]=c;
     arr[1][N]=d;   
        
     }  

      for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){

    
            printf("%d ",arr[i][j]); 
            }
      
            printf("\n");
        
    }
    return 0;    
} 
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
       

