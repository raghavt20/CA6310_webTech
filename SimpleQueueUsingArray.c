#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // For INT_MIN

#define SIZE 100

// Global variables
int queue[SIZE];
int front = -1;
int rear = -1;

// Function to enqueue an element
void enqueue(int item) {
    if (rear == SIZE - 1) {
        printf("Queue is full!\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = item;
        printf("Item added to queue: %d\n", item);
    }
}

// Function to dequeue an element
int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return -1;
    } else {
        int item = queue[front];
        front ++;
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        return item;
    }
}

// Function to display the queue
void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue contents:\n");
        int i;
        for (i = front; i <= rear; i++) {
            printf("%d\n", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, item;

    while(1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                printf("Enter an integer to enqueue: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2: 
                item = dequeue();
                if (item != -1) {
                    printf("Dequeued item: %d\n", item);
                }
                break;
            case 3: 
                display();
                break;
            case 4: 
                exit(0);
            default: 
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
