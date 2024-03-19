#include<stdio.h>
#include<string.h>
#include <stdlib.h>
typedef enum Account_type{
    savings,
    current
}Account_type;

typedef struct AccountInfo{
    int Account_Number;
    Account_type Account_Type;
    char Name[50];
    float Balance;
    struct AccountInfo* next;
}AccountInfo;

typedef AccountInfo* accountInfo;


void display(accountInfo l);
void lowbalanceAccounts(accountInfo l);
void transaction(accountInfo l,int accno,float amount,int code);
accountInfo deleteAccount(accountInfo l,char *acctype,char *name);

int main(){
    int code,accno;
    float amount;
    char acctype[50],name[50];
    //struct AccountInfo accountInfo;
    
    AccountInfo third = {102,current,"Riya",80.00,NULL};
    
    AccountInfo second = {101,current,"Ram",555.00, &third};
    
    AccountInfo first = {100,savings,"Sham",340.00,&second};
        
    accountInfo l = &first;

    int flag=1;
    while(flag=1)
    {
    char command[20];
    scanf("%s",command);
    if(strcmp(command,"DISPLAY")==0){
        display(l);
    }

    else if(strcmp(command,"LOWBALANCE")==0){
        lowbalanceAccounts(l);
    }

    else if(strcmp(command,"TRANSACTION")==0){
        scanf("%d %f %d",&accno,&amount,&code);
        transaction(l,accno,amount,code);
    }

    else if(strcmp(command,"DELETE")==0){
        scanf("%s %s",acctype,name);
        l=deleteAccount(l,acctype,name);
        while(l!=NULL)
        {
            printf("1\n");
            l=l->next;
        }

    }
    }

}
void display(accountInfo l) {
    char type[][10] = {
        "savings",
        "current"
    };
    printf("Account Number\tAccount Type\tName\t\tBalance\n");
    printf("-----------------------------------------------------\n");
    while (l != NULL) {
        printf("%d\t\t%s\t\t%s\t\t%f\n",l->Account_Number, type[l->Account_Type],l->Name,l->Balance);
        l = l->next;   
    }
}

void lowbalanceAccounts(accountInfo l){
    // char type[][10] = {
    //     "savings",
    //     "current"
    // };
    while(l !=NULL){
        if((l->Balance)<100){
            printf("Account Number: %d, Name: %s, Balance: %.2f\n",l->Account_Number,l->Name,l->Balance);
        }
        l = l->next;
    }

}

void transaction(accountInfo l,int accno,float amount,int code){
    while(l != NULL){
        if(l->Account_Number == accno){
            if(code==0){
                if((l->Balance)-amount >= 100){
                    printf("Updated balance is Rs: %.2f\n",(l->Balance)-amount);
                }

                else if((l->Balance)-amount < 100){
                    printf("The balance is insufficient for the specified withdrawal.\n");
                }
            }
            else if(code==1){
                printf("Updated balance is Rs: %.2f\n",(l->Balance)+amount);
            }

        
        }
        else if(l->Account_Number == accno && l==NULL){
            printf("Invalid: User does not exist\n");
        }
        l = l->next;
    }

}

accountInfo append(AccountInfo data,accountInfo l)
{
    AccountInfo* D = (AccountInfo *) malloc(sizeof(AccountInfo));
    D->Account_Number = data.Account_Number;
    D->Account_Type=data.Account_Type;
    D->Balance=data.Balance;
    strcpy(D->Name,data.Name);
    D->next = NULL;
    if (l == NULL) return D;
    accountInfo temp_list=l;
    while (l->next != NULL) {
        l = l->next;
    }
    l->next = D;
    return temp_list;

}

accountInfo deleteAccount(accountInfo l,char *acctype,char *name){
    char type[][10] = {
        "savings",
        "current"
    };

    AccountInfo* n = NULL;
    while(l != NULL){
        if(strcmp((type[l->Account_Type]),acctype)==0 && strcmp((l->Name),name)==0){
            l=l->next;
            printf("------\n");
        }
        else{
            
            n=append(*l,n);
            while(n!=NULL)
            {
                printf("%s\n",n->Name);
                n=n->next;
            }
            /* AccountInfo* node = (AccountInfo *) malloc(sizeof(AccountInfo));
            printf("*****\n");
            n->Account_Number = l->Account_Number;
            printf("*****\n");
            
            // char temp[10];
            // strcpy(temp,type[l->Account_Type]);
            // int i;
            // for(i=0;i<2;i++)
            // {
            //     if(strcmp(temp,type[i])==0)
            //         break;
            // }

            n->Account_Type=l->Account_Type;
            printf("*****\n");
            
            //type[n->Account_Type] = type[l->Account_Type];
            strcpy(n->Name,l->Name);
            n->Balance = l->Balance;
            n->next = l->next; */
            l=l->next;
        }
        
    }
    return n;
}

