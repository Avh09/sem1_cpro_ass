#include<stdio.h>
int main()
{
    int arr[]={1,13,2,5,6,7,2};
    int sum,n=7,currentsum=0;
    scanf("%d",&sum);
    for(int i=0;i<=n-1;i++)
    {
        for(int j=i;j<n;j++)
        {
            currentsum=currentsum+arr[j];
            if(currentsum==sum)
            {
                printf("Yayyyy");
                break;
            }
        }
    }
    return 0;
}