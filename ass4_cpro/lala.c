#include<stdio.h>
int main(){
    int startRead,endRead;
    float bill;
    printf("Enter starting meter reading: ");
    scanf("%d",&startRead);
    //printf("\n");
    printf("Enter ending meter reading: ");
    scanf("%d",&endRead);
    if(endRead-startRead<100){
        bill = (endRead-startRead)*(1.50);
        printf("Electricity bill: %.2f",bill);
    }
    else if(endRead-startRead>=100 && endRead-startRead<200){
        bill = (endRead-startRead)*(2.50);
        printf("Electricity bill: %.2f",bill);
    }
    else if(endRead-startRead>=200 && endRead-startRead<500){
        bill = (endRead-startRead)*(3.50);
        printf("Electricity bill: %.2f",bill);
    }
}
