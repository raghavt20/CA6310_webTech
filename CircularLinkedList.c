#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a node with a prev pointer
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev; // Added prev pointer
} Node;

// Function to create a new node
Node* CreateNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL; // Initialize prev to NULL
    return newNode;
}

// Function to add a node to an empty list
Node* AddToEmpty(Node* last, int data) {
    Node* newNode = CreateNode(data);
    if (newNode == NULL) return NULL;
    newNode->next = newNode; // Points to itself
    newNode->prev = newNode; // Points to itself
    return newNode;
}

// Function to add a node at the beginning of the list
Node* AddFront(struct Node* last, int data) {
    if (last == NULL)
        return AddToEmpty(last, data);
    Node* newNode = CreateNode(data);
    newNode->next = last->next;
    last->next = newNode;
    return last;
}

// Function to add a node at the end of the list
Node* AddEnd(Node* last, int data) {
    Node* newNode = CreateNode(data);
    if (newNode == NULL) return NULL;
    if (last == NULL) {
        return AddToEmpty(last, data);
    } else {
        newNode->next = last->next;
        newNode->prev = last;
        last->next->prev = newNode;
        last->next = newNode;
        return newNode;
    }
}

// Function to add a node after a specific node
Node* AddAfter(Node* last, int data, int item) {
    if (last == NULL) {
        printf("List is empty\n");
    }
    Node* newNode = CreateNode(data);
    Node* p = last->next;
    do {
        if (p->data == item) {
            newNode->next = p->next;
            newNode->prev = p;
            p->next->prev = newNode;
            p->next = newNode;
            if (p == last) {
                last = newNode;
            }
            return last;
        }
        p = p->next;
    } while (p != last->next);
    printf("Item not found\n");
    return NULL;
}

// Function to delete a node with a specific data
Node* DeleteNode(Node* last, int key) {
    if (last == NULL)
        return NULL;
    Node* temp = last;
    Node* d = NULL;
    if(last->data == key && last->next == last) {
        free(last);
        return NULL;
    }
    if(last->data == key) {
        while(temp->next !=last) {
            temp = temp -> next;
        }
        temp->next = last->next;
        last = temp->next;
    }
    while(temp->next != last && temp->next->data != key) {
        temp = temp->next;
    }
    if (temp->next->data == key) {
        d = temp->next;
        temp->next = d->next;
        d->next->prev = temp;
    }
    free(d);
    return last; // Return the last node if node not found
}

// Function to traverse and display the list
void Traverse(Node* last) {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* p = last->next; // Start from the last node
    do {
        printf("%d ", p->data);
        p = p->next; // Move to the previous node
    } while (p != last->next); // Stop when we reach the last node again
    printf("\n");
}

// Function to handle user input
void handleUserInput(Node** last) {
    int choice, data, item;
    bool quit = false;

    while (!quit) {
        printf("\nMenu:\n1. Add Front\n2. Add End\n3. Add After\n4. Delete Node\n5. Traverse\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                *last = AddFront(*last, data);
                break;
            case 2:
                printf("Enter the data: ");
                scanf("%d", &data);
                *last = AddEnd(*last, data);
                break;
            case 3:
                printf("Enter the data: ");
                scanf("%d", &data);
                printf("Enter the item after which to add: ");
                scanf("%d", &item);
                *last = AddAfter(*last, data, item);
                break;
            case 4:
                printf("Enter the key to delete: ");
                scanf("%d", &data);
                *last = DeleteNode(*last, data);
                break;
            case 5:
                Traverse(*last);
                break;
            case 6:
                quit = true;
                break;
            default:
                printf("Invalid choice\n");
        }
    }
}

int main() {
    Node* last = NULL;
    handleUserInput(&last);
    return 0;
}
