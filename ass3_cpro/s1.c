#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char str[9], a[9];
char array[40320][9];
int ct = 0;
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void permute(char *a, int l, int r)
{
    int i;
    int n = strlen(a);
    if (l == r)
    {
        // comp(a);
        strcpy(array[ct], a);
        ct++;
    }
    else
    {
        for (i = l; i <= r; i++)
        {
            swap((a + l), (a + i));
            permute(a, l + 1, r);

            // backtrack
            swap((a + l), (a + i));
        }
    }
}
static int cmpfunc(const void *a, const void *b)
{
    return strcmp((const char *)a, (const char *)b);
}
int main()
{
    scanf("%s", str);
    int n = strlen(str);
    permute(str, 0, n - 1);
    char **ray;
    char **ray1;
    int cm = 1;
    int ans[ct];
    ans[0] = 1;
    ray = (char **)malloc(ct * sizeof(char *));
    for (int i = 0; i < ct; i++)
    {
        ray[i] = (char *)malloc((n) * sizeof(char));
        strcpy(ray[i], array[i]);
    }
    qsort(ray, ct, sizeof(const char *), cmpfunc);
    for (int i = 0; i < ct; i++)
    {
        if (i != 0)
        {
            ans[i] = 0;
            if (strcmp(ray[i], ray[i - 1]) != 0)
            {
                ans[i] = 1;
                cm++;
            }
        }
    }
    printf("%d\n", cm);
    for (int i = 0; i < ct; i++)
    {
        if (ans[i] == 1)
        {
            for (int j = 0; j < n; j++)
                printf("%c", ray[i][j]);
            printf("\n");
        }
    }
    return 0;
}