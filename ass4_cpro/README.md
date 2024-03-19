# q1
### main function
- here I have created 3 accounts which are stored in linked list.
### code for display function
```c
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
```
- This function was required to be made as per the question.
- I have some accounts stored in my linked list which are being displyed when this display function is called. Also,if transaction function is called before and changes are made in the balance values, then the 'updated'balance values are displayed in the balance coloumn of this function.

### code for low balance function
```c
//Function for printing low balance accounts
void lowBalanceAccounts(accountInfo l){
    while(l !=NULL){
        if((l->data.Balance)<100){
            printf("Account Number: %d, Name: %s, Balance: %.2f\n",l->data.Account_Number,l->data.Name,l->data.Balance);
        }
        l = l->next;
    }
}
```
- This function was required to be made as per the question.
- I have some accounts stored in my linked list, this function iterates over those accounts to check if the balance in the account is less than 100 or no.

### code for transaction function
```c
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
```
- This function was required to be made as per the question.
- I have some accounts stored in my linked list, this function does transactions like deposite and withdrawal (following the necessary conditions of balance being above 100 after the transaction,also checks if or not the account number exists before making the transaction.)


# q2

### Assumptions:
- My structure has two arrays (as element of struct) c1 and c2 of the type float for storing the n-dimensional numbers and the maximum size of the above mentioned array is assumed to be "100000". 

### code for add function
```c
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

```
- Here in add function, once the operation is performed the result is printed here itself, i.e.,it's a void type function.

### code for sub function
```c
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
```
- Here in sub function, once the operation is performed the result is printed here itself, i.e.,it's a void type function.

### code for dot function
```c
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
```
- Here in dot function, once the operation is performed the result is printed here itself, i.e.,it's a void type function.

### code for cosineSimilarity function
```c
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
```
- Here in cosine function, once the operation is performed the result is printed here itself, i.e.,it's a void type function.



# q3
- If n=0, i.e., there are zero colours then my code prints "No colors".

### code for function "printLinkedList" - EXTRA FUNCTION
```c
// EXTRA FUNCTIONS
//Function to print modified Linked list
struct node* printLinkedList(struct node* ori){
    while (ori != NULL) {
        if(ori->next!=NULL){
            printf("%d -> ", ori->data);
        }
        else if(ori->next==NULL){
            printf("%d",ori->data);
        }
        ori = ori->next;
    }

}

```
- I have used the function "printLinkedList" to print the final modified list after the duplicates are removed. The linked list pointer named "ori" which intially points to NULL (in main function) is used to carry forward the loop. If ori->next is not pointing to NULL then "ori->data -> " is printed and if ori->next points to NULL then "ori->data" is printed without the "->" symbol. 


### code for function "removeDuplicates"
```c
//Function to remove duplicates
struct node* removeDuplicates(struct node* ori){
    struct node* present = ori;
    while(present != NULL && present->next != NULL){
        if(present->data == present->next->data){
            struct node* store = present->next;
            present->next = store->next;
            free(store);
        } 
        else{
            present = present->next;
        }
    }
    return ori;

}
```
- "removeDuplicates" is the function which was asked to be created as per the question.

