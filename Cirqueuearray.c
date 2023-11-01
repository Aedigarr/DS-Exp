#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int items[MAX_SIZE];
int front = -1, rear = -1;


void enqueue(int value) {
    if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1)) {
        printf("Queue is full, cannot enqueue element.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        items[rear] = value;
        printf("%d enqueued to queue.\n", value);
    }
}


int dequeue() {
    int item;
    if (front == -1) {
        printf("Queue is empty, cannot dequeue element.\n");
        return -1;
    } else {
        item = items[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        return item;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements are: ");
    int i;
    for (i = front; i != rear; i = (i + 1) % MAX_SIZE) {
        printf("%d ", items[i]);
    }
    printf("%d\n", items[i]);
}

int main() {
    int choice, value;
    do {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
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
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    return 0;
}
