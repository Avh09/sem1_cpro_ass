// #include <stdio.h>
// #include <math.h>

// // Define a struct to represent a complex number
// typedef struct {
//     float real;
//     float imag;
// } ComplexNumber;

// // Function to add two n-dimensional complex numbers
// ComplexNumber add(ComplexNumber c1, ComplexNumber c2) {
//     ComplexNumber result;
//     result.real = c1.real + c2.real;
//     result.imag = c1.imag + c2.imag;
//     return result;
// }

// // Function to subtract two n-dimensional complex numbers
// ComplexNumber sub(ComplexNumber c1, ComplexNumber c2) {
//     ComplexNumber result;
//     result.real = c1.real - c2.real;
//     result.imag = c1.imag - c2.imag;
//     return result;
// }

// // Function to calculate the dot product of two n-dimensional complex numbers
// float dot(ComplexNumber c1, ComplexNumber c2) {
//     return (c1.real * c2.real + c1.imag * c2.imag);
// }

// // Function to calculate the magnitude (modulus) of a complex number
// float modulus(ComplexNumber c) {
//     return sqrt(c.real * c.real + c.imag * c.imag);
// }

// // Function to calculate the cosine similarity between two n-dimensional complex numbers
// float cosineSimilarity(ComplexNumber c1, ComplexNumber c2) {
//     return dot(c1, c2) / (modulus(c1) * modulus(c2));
// }

// int main() {
//     int n;
//     while (1) {
//         printf("Enter operation and dimension (e.g., ADD 4, SUB 3, COSINE 2, DOT 2, -1 to exit): ");
//         char operation[10];
//         scanf("%s %d", operation, &n);

//         if (n == -1) {
//             break;
//         }

//         ComplexNumber c1, c2;
//         printf("Enter the values for C1 (real imag): ");
//         scanf("%f %f", &c1.real, &c1.imag);

//         printf("Enter the values for C2 (real imag): ");
//         scanf("%f %f", &c2.real, &c2.imag);

//         ComplexNumber result;
//         if (strcmp(operation, "ADD") == 0) {
//             result = add(c1, c2);
//         } else if (strcmp(operation, "SUB") == 0) {
//             result = sub(c1, c2);
//         } else if (strcmp(operation, "DOT") == 0) {
//             float dotProduct = dot(c1, c2);
//             printf("Result: %.2f\n", dotProduct);
//             continue;
//         } else if (strcmp(operation, "COSINE") == 0) {
//             float cosineSim = cosineSimilarity(c1, c2);
//             printf("Result: %.2f\n", cosineSim);
//             continue;
//         } else {
//             printf("Invalid operation.\n");
//             continue;
//         }

//         printf("Result: %.2f %.2f\n", result.real, result.imag);
//     }

//     return 0;
// }
#include<stdio.h>
#include<string.h>
#include<math.h>
void add(float c1[],float c2[],int n,float Result[]);
void sub(float c1[],float c2[],int n,float Result[]);
void dot(float c1[],float c2[],int n,float Result[]);
void cosineSimilarity(float c1[],float c2[],int n,float Result[]);

//Structure for complexNumber
typedef struct complexNumber{
    float c1[100000];
    float c2[100000];
}complexNumber;


int main(){
    float Result[100000],flag;
    struct complexNumber cmpno;
    char chutiyap[10];
    int n;
    for(int k=0;;k++){
        scanf("%s",chutiyap);  //String input eg: ADD,SUB,DOT,COSINE,-1
        if (strcmp(chutiyap,"-1")==0){
            break;
        }
        scanf("%d",&n); //Input number of dimensions 
        if(flag==0){
            for(int i=0;i<n;i++){
                scanf("%f",&cmpno.c1[i]);
            }
            for(int i=0;i<n;i++){
                scanf("%f",&cmpno.c2[i]);
            }
            if(strcmp(chutiyap,"ADD")==0){
                flag=0;
                add(cmpno.c1,cmpno.c2,n,Result);
            }
            else if(strcmp(chutiyap,"SUB")==0){\
                flag=0;
                sub(cmpno.c1,cmpno.c2,n,Result);
            }
            else if(strcmp(chutiyap,"DOT")==0){
                flag=0;
                dot(cmpno.c1,cmpno.c2,n,Result);
            }
            else if(strcmp(chutiyap,"COSINE")==0){
                flag=0;
                cosineSimilarity(cmpno.c1,cmpno.c2,n,Result);
            }
        }    
    }


}

//Function to add
void add(float c1[],float c2[],int n,float Result[]){
    for(int i=0;i<n;i++){
        Result[i] = c1[i]+c2[i];
    }
    printf("Result: ");
    for(int i=0;i<n;i++){
        printf("%.2f ",Result[i]);}
        printf("\n");
}

//Function to subtract
void sub(float c1[],float c2[],int n,float Result[]){
    for(int i=0;i<n;i++){
        Result[i] = c1[i]-c2[i];
    }
    printf("Result: ");
    for(int i=0;i<n;i++){
        printf("%.2f ",Result[i]);
    }
    printf("\n");
}

//Function to obtain dot
void dot(float c1[],float c2[],int n,float Result[]){
    float sum=0;
    for(int i=0;i<n;i++){
        Result[i] = c1[i]*c2[i];
        sum+=Result[i];
    }

    printf("Result: ");
    printf("%.2f ",sum);
    printf("\n");
    
}

//Function cosineSimilarity
void cosineSimilarity(float c1[],float c2[],int n,float Result[]){
    float sum=0,sum1=0,sum2=0;
    for(int i=0;i<n;i++){
        Result[i] = c1[i]*c2[i];
        sum+=Result[i];
    }

    
    for(int i=0;i<n;i++){
        sum1+=pow((c1[i]),2);
    }
    for(int i=0;i<n;i++){
        sum2+=pow((c2[i]),2);
    }

    float ans = sum/((sqrt(sum1))*(sqrt(sum2)));

    printf("Result: ");
    printf("%.2f ",ans);
    printf("\n");
    
}