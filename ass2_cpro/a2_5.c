#include<stdio.h>

int main(){
    int N,k,l;
    // int Dmax;
    // int Cmin;
    // int Bmax;
    // int Amin;
    scanf("%d",&N);
    int arr[N][4];
    for(int i=0;i<N;i++){
        for(int j=0;j<4;j++){
        scanf("%d",&arr[i][j]);
        }

    }

    int grid[100][100];
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++)
            grid[i][j]=0;
        }

        for(int i=0;i<N;i++){
            for(int k=arr[i][0];k<arr[i][1];k++){
                for(int j=arr[i][2];j<arr[i][3];j++){
                    grid[k][j]=1;
                }
            }
        }
        int amin=arr[0][0];
        int bmax=arr[0][1];
        int cmin=arr[0][2];
        int dmax=arr[0][3];

        for(int i=0;i<N;i++){
            // int Dmax=fmax(arr[i][3]);
            // int Dmin=fmin(arr[i][3]);
            // int Cmax=fmax(arr[i][2]);
            // int Cmin=fmin(arr[i][2]);
            // int Bmax=fmax(arr[i][1]);
            // int Bmin=fmin(arr[i][1]);
            // int Amax=fmax(arr[i][0]);
            // int Amin=fmin(arr[i][0]);
            if(amin>arr[i][0]){
                amin=arr[i][0];
            }
            if(bmax<arr[i][1]){
                bmax=arr[i][1];
            }
            if(cmin>arr[i][2]){
                cmin=arr[i][2];
            }
            if(dmax<arr[i][3]){
                dmax=arr[i][3];
            }
        }
       // printf("%d %d %d %d",amin,bmax,cmin,dmax);

        int Area=((dmax-cmin)*(bmax-amin));
         int c=0;
        for(int i=amin;i<bmax;i++){
            for(int j=cmin;j<dmax;j++){
               
                    if(grid[i][j]==0)
                        c++;
            }
        }

        int ans=Area-c;

        printf("%d",ans);

    return 0;
}