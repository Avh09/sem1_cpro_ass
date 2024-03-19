#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *permute(char *a, int l, int r);
int ct=0;
static int cmpfunc(const void* a, const void* b) 
{ 
    return strcmp(*(const char**)a, *(const char**)b); 
} 

char str[9],a[9];
char array[40320][9];

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
    permute(str, 0, n-1);
    char ray[ct][n];
    for(int i=0;i<ct;i++)
    {
        strcpy(ray[i],array[i]);
    }
    int chu = sizeof(ray) / sizeof(ray[0]);
    qsort(ray, chu, sizeof(const char*),cmpfunc);
    for(int i=0;i<ct;i++)
    {
        for(int j=0;j<n;j++)
        printf("%c",ray[i][j]);
        printf("\n");
    }
} 
char *permute(char *a, int l, int r) 
{ 
    int i;
    int n = strlen(a); 
    if (l == r){
        //comp(a); 
        strcpy(array[ct],a);
        ct++;
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
     
} 







