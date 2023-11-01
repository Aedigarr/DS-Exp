#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// Initialize stack
void initialize(Stack* stack) {
    stack->top = -1;
}

// Check if stack is full
int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Check if stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Push an element to the stack
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full, cannot push element.\n");
    } else {
        stack->top++;
        stack->items[stack->top] = value;
        printf("%d pushed to stack.\n", value);
    }
}

// Pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty, cannot pop element.\n");
        return -1;
    } else {
        int popped = stack->items[stack->top];
        stack->top--;
        return popped;
    }
}

// Main function
int main() {
    Stack stack;
    initialize(&stack);
    int choice, value;
    do {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
    return 0;
}

