#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include<math.h>
char *permute(char *a, int l, int r);

int cmpfunc( const void *pa, const void *pb) {
  return strcmp(pa,pb);
}
void comp(char *lol) {
 qsort(lol, strlen(lol), sizeof(lol[0]), cmpfunc);
}

char str[8],a[8];
char array[40320][8];

void swap(char *x, char *y) 
{ 
    char temp; 
    temp = *x; 
    *x = *y; 
    *y = temp; 
} 
void main() 
{   scanf("%s",str);
    int n = strlen(str);
    //char array[tgamma(n+1)][n];
    //printf("%d",n);
    
    for(int i=0;i<n;i++){
        permute(str, i, n-1);
        for(int j=0;j<n;j++){
            printf("%c",a[j]);
        array[i][j]=a[j];
        }
    }
    printf("fckkk");

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        printf("%c...\n",array[i][j]);
    }

    printf("fckkk2");

    //return 0; 
} 
char *permute(char *a, int l, int r) 
{ 
    int i;
    int n = strlen(a); 
    if (l == r){
    //    char array[tgamma(n+1)][n] = a;
        //for(int i=0;i<n;i++){ 
        //printf("wtf : %s\n", a);
        //}
        comp(a); 
        //return a;
    }    
    else
    { 
        for (i = l; i <= r; i++) 
        { 
            swap((a + l), (a + i)); 
            permute(a, l + 1, r); 
  
            //backtrack 
            swap((a + l), (a + i));  
        } 
    }
     //comp(lol);
    // for(int i=1;i<=n;i++){
    // printf("%s\n",lol);
    // }
    // for(i = 0; i < 3; i++) 
    //     printf("%s\n", array[i]); 
  
} 







