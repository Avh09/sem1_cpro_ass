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
}AccountInfo;

typedef struct Node{
    AccountInfo data;
    struct Node* next;
}Node;

typedef Node* accountInfo;
void display(accountInfo l);
void lowbalanceAccounts(accountInfo l);
void transaction(accountInfo l,int accno,float amount,int code);
accountInfo deleteAccount(accountInfo l,char *acctype,char *name);
accountInfo append(AccountInfo data,accountInfo l);

int main(){
    int code,accno;
    float amount;
    char acctype[50],name[50];
    //struct AccountInfo accountInfo;
    
    AccountInfo third = {102,current,"Riya",80.00};
    Node node1={third,NULL};
    
    AccountInfo second = {101,current,"Ram",555.00};
    Node node2={second,&node1};
    
    AccountInfo first = {100,savings,"Sham",340.00};
    Node node3={first,&node2};
        
    accountInfo l = &node3;

    AccountInfo data={109,savings,"Anany",200};
    l=append(data,l);

    AccountInfo data2={111,savings,"Ananya",200};
    l=append(data2,l);

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


    
     if(strcmp(command,"DELETE")==0){
        scanf("%s %s",acctype,name);
        l=deleteAccount(l,acctype,name);
        while(l!=NULL)
        {
            printf("%s...",l->data.Name);
            l=l->next;
        }
        // while(l!=NULL)
        // {
        //     printf("1\n");
        //     l=l->next;
        // }

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
        printf("%d\t\t%s\t\t%s\t\t%f\n",l->data.Account_Number, type[l->data.Account_Type],l->data.Name,l->data.Balance);
        l = l->next;   
    }
}

void lowbalanceAccounts(accountInfo l){
    while(l !=NULL){
        if((l->data.Balance)<100){
            printf("Account Number: %d, Name: %s, Balance: %.2f\n",l->data.Account_Number,l->data.Name,l->data.Balance);
        }
        l = l->next;
    }

}

void transaction(accountInfo l,int accno,float amount,int code){
    while(l != NULL){
        if(l->data.Account_Number == accno){
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
        else if(l->data.Account_Number == accno && l==NULL){
            printf("Invalid: User does not exist\n");
        }
        l = l->next;
    }

}

accountInfo append(AccountInfo data,accountInfo l)
{
   Node* D = (Node *) malloc(sizeof(Node));
    D->data = data;
    D->next = NULL;
    if (l == NULL)
        return D;
    accountInfo temp_list=l;
    while (l->next != NULL) {
        l = l->next;
    }
    l->next = D;
    return temp_list;

}

void deleteNode(accountInfo* head_ref, char Name[], char acctype[]) 
{ 
    // Store head node 
    struct Node *temp = *head_ref, *prev; 
  
    // If head node itself holds the key to be deleted 
    if (temp != NULL && strcmp((type[l->data.Account_Type]),acctype)==0 && strcmp((l->data.Name),name)==0) { 
        *head_ref = temp->next; // Changed head 
        free(temp); // free old head 
        return; 
    } 
  
    // Search for the key to be deleted, keep track of the 
    // previous node as we need to change 'prev->next' 
    while (temp != NULL && strcmp((type[l->data.Account_Type]),acctype)==0 && strcmp((l->data.Name),name)==0) { 
        prev = temp; 
        temp = temp->next; 
    } 
  
    // If key was not present in linked list 
    if (temp == NULL) 
        return; 
  
    // Unlink the node from linked list 
    prev->next = temp->next; 
  
    free(temp); // Free memory 
} 
/* 
accountInfo delete_by_name(accountInfo l, char *acctype,char *name) {
    char type[][10] = {
        "savings",
        "current"
    };
    if (l == NULL) {
        return NULL;
    } else if (strcmp((type[l->data.Account_Type]),acctype)==0 && strcmp((l->data.Name),name)==0) {
        // 
        Node* tail = NULL;
        if(l->next==NULL)
printf("####\n");
        tail=l->next;
        free(l);
        if(tail==NULL)
        printf("nnono\n");
        
        return tail;
    } else {
        l->next = delete_by_name(l->next, acctype, name);
         if(l->next==NULL)  
            printf("####\n");
        return l;
    }
} */

accountInfo deleteAccount(accountInfo l,char *acctype,char *name){
    
    int flag=0;
    char type[][10] = {
        "savings",
        "current"
    };
    // display(l);
    // accountInfo n = NULL;
    // accountInfo new=NULL;
    accountInfo temp=l;
    while(l!= NULL ){
        if(strcmp((type[l->data.Account_Type]),acctype)==0 && strcmp((l->data.Name),name)==0){
            l=deleteNode(l,acctype,name);
            printf("Deleted\n");
            display(l);
            flag=-1;
        }
        else{
            l=l->next;
        }
    }
    
    if (flag==0){
        printf("Invalid\n");
    }

    return temp;

}