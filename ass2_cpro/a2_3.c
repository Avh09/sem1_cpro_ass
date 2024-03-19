#include<stdio.h>
#include<math.h>
int main(){
    long long int n,i;
    int root;

     scanf("%lld",&n);


         for(long long int i=1; i<=sqrt(n);i++)
        {
        
        if(i*i<=n)
           printf("%lld ",i*i);
          
        }
   

    return 0;
}