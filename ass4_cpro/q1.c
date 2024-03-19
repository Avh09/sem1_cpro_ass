#include<stdio.h>
#include<string.h>
#include <stdlib.h>

//Enum for account type i.e., savings or current
typedef enum Account_type{
    savings,
    current
}Account_type;

//Structure AccountInfo
typedef struct AccountInfo{
    int Account_Number;
    Account_type Account_Type;
    char Name[50];
    float Balance;
}AccountInfo;

//Creating structure for a node in linked list
typedef struct Node{
    AccountInfo data;
    struct Node* next;
}Node;
typedef Node* accountInfo;

void display(accountInfo l);
void lowBalanceAccounts(accountInfo l);
void transaction(accountInfo l,int accno,float amount,int code);

int main(){
    int code,accno;
    float amount;
    char acctype[50],name[50];
    
    AccountInfo third = {102,current,"Riya",80.00};
    Node node1={third,NULL};
    
    AccountInfo second = {101,current,"Ram",555.00};
    Node node2={second,&node1};
    
    AccountInfo first = {100,savings,"Sham",340.00};
    Node node3={first,&node2};
        
    accountInfo l = &node3;

    
    char command[20];
    for(int k=0;;k++){
        scanf("%s",command);

        if(strcmp(command,"EXIT")==0){
            break;
        }

        else if(strcmp(command,"DISPLAY")==0){
            display(l);
        }

        else if(strcmp(command,"LOWBALANCE")==0){
            lowBalanceAccounts(l);
        }

        else if(strcmp(command,"TRANSACTION")==0){
            scanf("%d %f %d",&accno,&amount,&code);
            transaction(l,accno,amount,code);
        }
    }

}   

//Function for display
void display(accountInfo l) {
    char type[][10] = {
        "savings",
        "current"
    };
    printf("Account Number\tAccount Type\tName\t\tBalance\n");
    printf("-----------------------------------------------------\n");
    while (l != NULL) {
        printf("%d\t\t%s\t\t%s\t\t%f\n",l->data.Account_Number, type[l->data.Account_Type],l->data.Name,l->data.Balance);
        l = l->next;   
    }
}

//Function for printing low balance accounts
void lowBalanceAccounts(accountInfo l){
    while(l !=NULL){
        if((l->data.Balance)<100){
            printf("Account Number: %d, Name: %s, Balance: %.2f\n",l->data.Account_Number,l->data.Name,l->data.Balance);
        }
        l = l->next;
    }
}

//Function for making transactions
void transaction(accountInfo l,int accno,float amount,int code){
    int flag=0;
    while(l != NULL){
        if(l->data.Account_Number == accno){
            flag=1;
            if(code==0){
                if((l->data.Balance)-amount >= 100){
                    l->data.Balance-=amount;
                    printf("Updated balance is Rs: %.2f\n",(l->data.Balance));
                }

                else if((l->data.Balance)-amount < 100){
                    printf("The balance is insufficient for the specified withdrawal.\n");
                }
            }
            else if(code==1){
                l->data.Balance+=amount;
                printf("Updated balance is Rs: %.2f\n",(l->data.Balance));
            }
        }
        l = l->next;
    }
    
    if(flag==0){
        printf("Invalid: User does not exist\n");
    }

}