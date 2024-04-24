#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a node
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) return;
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Function to insert a node at the end of the list
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) return;
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* last = *head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
        newNode->prev = last;
    }
}

// Function to insert a node after a specific node
void insertAfter(Node* tempNode, int data) {
    if (tempNode == NULL) {
        printf("Node is NULL\n");
        return;
    }
    Node* newNode = createNode(data);
    if (newNode == NULL) return;
    newNode->next = tempNode->next;
    newNode->prev = tempNode;
    if (tempNode->next != NULL) {
        tempNode->next->prev = newNode;
    }
    tempNode->next = newNode;
}

// Function to delete a node
void deleteNode(Node** head, Node* tempNode) {
    if (*head == NULL || tempNode == NULL) {
        printf("List is empty or node is NULL\n");
        return;
    }
    if (tempNode->prev != NULL) {
        tempNode->prev->next = tempNode->next;
    } else {
        *head = tempNode->next;
    }
    if (tempNode->next != NULL) {
        tempNode->next->prev = tempNode->prev;
    }
    free(tempNode);
}

// Function to display the list
void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    int choice, data, position;
    bool quit = false;
    Node* tempNode = NULL;

    while (!quit) {
        printf("\nMenu:\n1. Insert at beginning\n2. Insert at end\n3. Insert after a node\n4. Delete a node\n5. Print list\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter the data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter the data: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &position);
                tempNode = head;
                for (int i = 0; i < position && tempNode != NULL; i++) {
                    tempNode = tempNode->next;
                }
                if (tempNode == NULL) {
                    printf("Position out of range\n");
                } else {
                    insertAfter(tempNode, data);
                }
                break;
            case 4:
                printf("Enter position: ");
                scanf("%d", &position);
                tempNode = head;
                for (int i = 0; i < position && tempNode != NULL; i++) {
                    tempNode = tempNode->next;
                }
                if (tempNode == NULL) {
                    printf("Position out of range\n");
                } else {
                    deleteNode(&head, tempNode);
                }
                break;
            case 5:
                displayList(head);
                break;
            case 6:
                printf("Exiting...\n");
                quit = true;
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}