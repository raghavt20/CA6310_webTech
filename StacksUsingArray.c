#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

int top = -1, inp_array[SIZE];

// Function to push an element onto the stack
void push() {
    int x;
    if (top >= SIZE - 1) {
        printf("Overflow!!\n");
    } else {
         printf("Enter data to be added onto the stack: ");
        scanf("%d", &x);
        top++;
        inp_array[top] = x;   
    }
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Underflow!!\n");
    } else {
        printf("\nPopped element: %d", inp_array[top]);
        top = top - 1;
    }
}

// Function to display the stack
void show() {
    if (top == -1) {
        printf("Underflow!!\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", inp_array[i]);
        }
    }
}

int main() {
    int choice;

    while(1) {
        printf("\nPerform operations on the stack: \n");
        printf("1. Push the element\n");
        printf("2. Pop the element\n");
        printf("3. Show\n");
        printf("4. End\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                push();
                break;
            case 2: 
                pop();
                break;
            case 3: 
                show();
                break;
            case 4: 
                exit(0);
            default: 
                printf("Invalid choice, please try again.\n");
        }
        printf("\n");
    }

    return 0;
}
