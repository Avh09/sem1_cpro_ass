#include<stdio.h>
int main()
{
    int w,h,j;

    scanf("%d %d",&w,&h);
for(int i=0;i<h;i++)
{
    if(i==0 || i==(h-1))
    {
        for(int j=0;j<w;j++)
        {  
            if(j==0 || j==(w-1))

                {printf("o");
            
                }
            

             else
                printf("-");
      
        }       

    }   
    else
       {
        for(int j=0;j<w;j++)
        {
            if(j==0 || j==(w-1))
                printf("|");

            else
                printf(" ");
        }
       }

    printf("\n");
}
return 0;
}