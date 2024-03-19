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
    char command[10];
    int n;
    for(int k=0;;k++){
        scanf("%s",command);  //String input eg: ADD,SUB,DOT,COSINE,-1
        if (strcmp(command,"-1")==0){
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
            if(strcmp(command,"ADD")==0){
                flag=0;
                add(cmpno.c1,cmpno.c2,n,Result);
            }
            else if(strcmp(command,"SUB")==0){\
                flag=0;
                sub(cmpno.c1,cmpno.c2,n,Result);
            }
            else if(strcmp(command,"DOT")==0){
                flag=0;
                dot(cmpno.c1,cmpno.c2,n,Result);
            }
            else if(strcmp(command,"COSINE")==0){
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
