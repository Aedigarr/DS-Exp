#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int items[MAX_SIZE];
int front = -1, rear = -1;

int isFull() {
    return (rear == MAX_SIZE - 1);
}

int isEmpty() {
    return (front == -1 && rear == -1);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full, cannot enqueue element.\n");
    } else {
        if (isEmpty()) {
            front = 0;
        }
        rear++;
        items[rear] = value;
        printf("%d enqueued to queue.\n", value);
    }
}

int dequeue() {
    int item;
    if (isEmpty()) {
        printf("Queue is empty, cannot dequeue element.\n");
        return -1;
    } else {
        item = items[front];
        if (front >= rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
        return item;
    }
}


int main() {
    int choice, value;
    do {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
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
