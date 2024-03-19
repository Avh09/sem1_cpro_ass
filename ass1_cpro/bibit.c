#include<stdio.h>

int main()
{
  int n,a,b;
  scanf("%d",&n);

  int arr[33];
  for(int i=31;i>=0;i--)
  {      
    
    if (n & 1<<i)
    {
      arr[i] =1;
    }
    else
    {
      arr[i] = 0;
    }

  }


  for(int i=31;i>=0;i--)
  {
    if(arr[i]==1)
    {
    b=i;
    break;
    }

    }

    for(int i=b;i>=0;i--)
    {
      printf("%d",arr[i]);
    }
    
  
    return 0;
    
  }

  


 