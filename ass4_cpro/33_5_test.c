#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to remove duplicates from the linked list
struct Node* removeDuplicates(struct Node* head) {
    if (head == NULL) {
        return head;
    }

    struct Node* current = head;

    while (current->next != NULL) {
        if (current->data == current->next->data) {
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }

    return head;
}

// Function to print the modified linked list
void printLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    int n;
    printf("Enter the number of colors in the list: ");
    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* tail = NULL;

    printf("Enter the colors: ");
    for (int i = 0; i < n; i++) {
        int color;
        scanf("%d", &color);

        // Create a new node for the color
        struct Node* newNode = createNode(color);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Remove duplicates from the linked list
    head = removeDuplicates(head);

    // Print the modified linked list
    printf("Modified Linked List: ");
    printLinkedList(head);

    // Free memory
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
