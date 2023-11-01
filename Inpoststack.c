#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

bool isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, char item) {
    if (isFull(stack)) {
        printf("Stack is full.\n");
    } else {
        stack->top++;
        stack->items[stack->top] = item;
    }
}

char pop(Stack* stack) {
    if (isEmpty(stack)) {
        return '\0';
    } else {
        char item = stack->items[stack->top];
        stack->top--;
        return item;
    }
}

int priority(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else
        return 0;
}

int main()
{
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    Stack stack;
    stack.top = -1;
    int i = 0;
    int j = 0;

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    while (infix[i] != '\0') {
        char ch = infix[i];
        if (isalnum(ch)) {
            postfix[j] = ch;
            j++;
        } else if (ch == '(') {
            push(&stack, ch);
        } else if (ch == ')') {
            while (stack.top != -1 && stack.items[stack.top] != '(') {
                postfix[j] = pop(&stack);
                j++;
            }
            if (stack.top != -1 && stack.items[stack.top] == '(') {
                pop(&stack); // Discard the '('
            }
        } else {
            while (stack.top != -1 && priority(ch) <= priority(stack.items[stack.top])) {
                postfix[j] = pop(&stack);
                j++;
            }
            push(&stack, ch);
        }
        i++;
    }

    while (stack.top != -1) {
        postfix[j] = pop(&stack);
        j++;
    }
    postfix[j] = '\0';

    printf("Infix Expression: %s\n", infix);
    printf("Postfix Expression: %s\n", postfix);
    return 0;
}
