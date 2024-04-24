#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Global variable for the top of the stack
Node* top = NULL;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Heap Overflow\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(int data) {
    Node* newNode = createNode(data);
    if (newNode != NULL) {
        newNode->next = top;
        top = newNode;
    }
}

// Function to pop an element from the stack
void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    Node* temp = top;
    top = top->next;
    free(temp);
}

// Function to peek the top element of the stack
int peek() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1; // Return -1 or any other value to indicate an error
    }
    return top->data;
}

// Function to display the stack
void display() {
    Node* temp = top;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    int choice, data;

    while(1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2: 
                pop();
                break;
            case 3: 
                printf("Top element is %d\n", peek());
                break;
            case 4: 
                display();
                break;
            case 5: 
                printf("Exiting...\n");
                exit(0);
                break;
            default: 
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
