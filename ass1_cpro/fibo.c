#include<stdio.h>
int main()
{
    int n,x,y;
    
    scanf("%d %d %d",&n,&x,&y);
    
    int sum=x+y;

    if(n<=1) 
    printf("%d ",x);

    else
    printf("%d %d ",x,y);


    for(int i=1;i<=(n-2);i++)
    {
    
    sum=x+y;
    x=y;
    y=sum;
    
    printf("%d ",sum);
    
    }
}