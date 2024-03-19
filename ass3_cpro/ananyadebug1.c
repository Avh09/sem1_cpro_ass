#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b)
{
    return *(char *)a - *(char *)b;
}

void comp(char str[])
{
    qsort(str, strlen(str), sizeof str[0], cmpfunc);
}

int main()
{
    char str[100];
    int flag=0;
    scanf("%s", str);
    int n = strlen(str);
    // printf("%d\n",n);
    //  if(n==1){
    //      printf("No");
    //  }

    comp(str);
    //       for(int i=0;i<n;i++){
    //   printf("%c",str[i]);
    // }
    // printf("\n");
    for (int i = 0; i < n; i++)
    {
        
        // printf("%c\n",str[0]);
        //  if(str[i]==' '){
        //      printf("g");
        //      continue;
        //  }
        // printf("\n%c\n",str[n-1]);

        if ((int)str[n - 1] < 97 && (int)str[i] >= 65)
        {
            // printf("%c%c\n",str[n-1],str[i]);
           // printf("k");

            flag = 2;
            printf("No");

            break;
        }
        
    if(i>0 && (int)str[i-1]<=90){
        if ((int)str[i] >= 97 && str[i]!=str[i+1])
        {
            //printf("%d", i);
             //printf("%c\n", str[i-1]);
            flag = 3;
            // printf("Noooo");
            break;
        }
        
    }
    else {
            flag = 4;
        }
        //  if(str[i]!=' ' && str[i]>='a'){
        // // // //     printf("%c\n",str[i]);
        // //      printf("No");
        // //     break;
        // //  }

        //  else if(str[n-1]<='z' && str[i]>='a'){
        //     printf("h");
        //     printf("%d %c\n",i,str[i]);
        //     flag=3;
        //     printf("No");

        //      break;
        //  }
        // if(str[i]>='a'){
        //     flag=3;
        //     printf("No");
        //     break;
        // }

       if (str[i] - str[i + 1] == 0)
        {
            flag = 1;
            break;
        }
        // else((int)str[i])
        // break;
    }
    //printf("%d", flag);
    // for(int i=0;i<n;i++){
    //     flag=0;
    // if(str[i]-str[i+1]==){
    //         flag=1;
    //     }
    // }
    //printf("%d",flag);

    if(flag==3){
        for(int i=0;i<n;i++){
            if(str[i]-str[i+1]==0){
                flag=4;
                break;
            }
            else{
                flag=3;
            }
        }

    }

    if (flag == 1 || flag == 4)
    {
        printf("No");
    }
    else if (flag == 0 || flag == 3)
    {
        printf("Yes");
    }

    return 0;
}