#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Enum for Account Type
typedef enum {
    SAVINGS,
    CURRENT
} AccountType;

// Struct for Account Info
typedef struct {
    int accountNumber;
    AccountType accountType;
    char name[50];
    float balance;
    struct AccountInfo* next;
} AccountInfo;

// Global pointer for the head of the account list
AccountInfo* accountList = NULL;

// Function to generate a new account number
int generateAccountNumber() {
    static int accountNumber = 100;
    return accountNumber++;
}

// Function to create a new account
void createAccount(AccountType accountType, char* name, float amount) {
    AccountInfo* current = accountList;
    
    while (current != NULL) {
        if (current->accountType == accountType && strcmp(current->name, name) == 0) {
            printf("Invalid: User already exists!\n");
            return;
        }
        current = current->next;
    }
    
    // Account does not exist, create a new one
    AccountInfo* newAccount = (AccountInfo*)malloc(sizeof(AccountInfo));
    newAccount->accountNumber = generateAccountNumber();
    newAccount->accountType = accountType;
    strcpy(newAccount->name, name);
    newAccount->balance = amount;
    newAccount->next = accountList;
    accountList = newAccount;
    
    printf("Account Number: %d\n", newAccount->accountNumber);
    printf("Account Holder: %s\n", newAccount->name);
    printf("Account Type: %s\n", (accountType == SAVINGS) ? "Savings" : "Current");
    printf("Balance: Rs %.2f\n", newAccount->balance);
}

// Function to delete an account
void deleteAccount(AccountType accountType, char* name) {
    AccountInfo* current = accountList;
    AccountInfo* prev = NULL;
    while (current != NULL) {
        if (current->accountType == accountType && strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                accountList = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Account deleted successfully\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Invalid: User does not exist\n");
}

// Function to display all accounts
void displayAccounts() {
    AccountInfo* current = accountList;
    if (current == NULL) {
        printf("No Accounts to display\n");
        return;
    }
    printf("Account Number Account Type Name Balance\n");
    printf("---------------------------------------------------------------\n");
    while (current != NULL) {
        printf("%d %s %s Rs %.2f\n", current->accountNumber,
               (current->accountType == SAVINGS) ? "Savings" : "Current",
               current->name, current->balance);
        current = current->next;
    }
}

// Function to display low balance accounts
void lowBalanceAccounts() {
    AccountInfo* current = accountList;
    printf("Low Balance Accounts:\n");
    while (current != NULL) {
        if (current->balance < 100) {
            printf("Account Number: %d, Name: %s, Balance: Rs %.2f\n",
                   current->accountNumber, current->name, current->balance);
        }
        current = current->next;
    }
}

// Function to perform transactions (deposit or withdrawal)
void transaction(int accountNumber, float amount, int code) {
    AccountInfo* current = accountList;
    while (current != NULL) {
        if (current->accountNumber == accountNumber) {
            if (code == 1) { // Deposit
                current->balance += amount;
                printf("Updated balance is Rs %.2f\n", current->balance);
            } else if (code == 0) { // Withdrawal
                if (current->balance - amount < 100) {
                    printf("The balance is insufficient for the specified withdrawal.\n");
                } else {
                    current->balance -= amount;
                    printf("Updated balance is Rs %.2f\n", current->balance);
                }
            }
            return;
        }
        current = current->next;
    }
    printf("Invalid: User does not exist\n");
}

int main() {
    char command[20];
    while (1) {
        printf("Enter a command (CREATE, DELETE, TRANSACTION, LOWBALANCE, DISPLAY, EXIT): ");
        scanf("%s", command);
        
        if (strcmp(command, "CREATE") == 0) {
            int accountType;
            char name[50];
            float amount;
            scanf("%d %s %f", &accountType, name, &amount);
            createAccount((AccountType)accountType, name, amount);
        } else if (strcmp(command, "DELETE") == 0) {
            int accountType;
            char name[50];
            scanf("%d %s", &accountType, name);
            deleteAccount((AccountType)accountType, name);
        } else if (strcmp(command, "TRANSACTION") == 0) {
            int accountNumber, code;
            float amount;
            scanf("%d %f %d", &accountNumber, &amount, &code);
            transaction(accountNumber, amount, code);
        } else if (strcmp(command, "LOWBALANCE") == 0) {
            lowBalanceAccounts();
        } else if (strcmp(command, "DISPLAY") == 0) {
            displayAccounts();
        } else if (strcmp(command, "EXIT") == 0) {
            break;
        }
    }
    
    // Clean up allocated memory
    AccountInfo* current = accountList;
    while (current != NULL) {
        AccountInfo* temp = current;
        current = current->next;
        free(temp);
    }
    
    return 0;
}
