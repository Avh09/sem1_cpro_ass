#include<stdio.h>
#include<stdlib.h>

struct node* removeDuplicates(struct node* ori);
struct node* printLinkedList(struct node* ori);
//Creating structure for a node in linked list
struct node{
    int data;
    struct node* next;
};

int main(){
    int n;
    printf("Enter the number of colors in the list: ");
    scanf("%d",&n);

    if (n <= 0){
        printf("No colors.\n");
        return 0;
    }

    struct node* ori = NULL;
    struct node* follower = NULL;

    printf("Enter the colors: ");
    for (int i = 0; i < n; i++) {
        int colour;
        scanf("%d", &colour);
    
        if(i!=0){
            follower->next = (struct node*)malloc(sizeof(struct node));
            follower = follower->next;
            follower->data = colour;
            follower->next = NULL;

        }
        else if(i==0){
            ori = (struct node*)malloc(sizeof(struct node));
            ori->data = colour;
            ori->next = NULL;
            follower = ori;
        }
    }
    ori = removeDuplicates(ori);
    printf("Modified Linked List: ");
    printLinkedList(ori);
}

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