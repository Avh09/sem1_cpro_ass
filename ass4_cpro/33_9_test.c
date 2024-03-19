#include <stdio.h>
#include <stdlib.h>

//structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

//remove duplicate colors in the linked list
struct Node* removeDuplicates(struct Node* head) {
    struct Node* chu = head;
    
    while (chu != NULL && chu->next != NULL) {
        if (chu->data == chu->next->data) {
            struct Node* temp = chu->next;
            chu->next = temp->next;
            free(temp);
        } else {
            chu = chu->next;
        }
    }
    
    return head;
}

//print the modified linked list
void printLinkedList(struct Node* head) {
    while (head != NULL) {
        
        if(head->next!=NULL){
            printf("%d -> ", head->data);
        }
        else if(head->next==NULL){
            printf("%d",head->data);
        }
        head = head->next;
    }
    
}

int main() {
    int n;
    printf("Enter the number of colors in the list: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("No colors to input.\n");
        return 0;
    }

    struct Node* head = NULL;
    struct Node* tail = NULL;

    printf("Enter the colors: ");
    for (int i = 0; i < n; i++) {
        int color;
        scanf("%d", &color);

        if (i == 0) {
            head = (struct Node*)malloc(sizeof(struct Node));
            head->data = color;
            head->next = NULL;
            tail = head;
        } 
        else {
            tail->next = (struct Node*)malloc(sizeof(struct Node));
            tail = tail->next;
            tail->data = color;
            tail->next = NULL;
        }
    }

    head = removeDuplicates(head);

    printf("Modified Linked List: ");
    printLinkedList(head);

    // Free memory used by linked list
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
