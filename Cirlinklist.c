#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert_beg(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = data;
    new_node->next = *head_ref;

    if (*head_ref == NULL) {
        new_node->next = new_node;
    } else {
        while (last->next != *head_ref) {
            last = last->next;
        }
        last->next = new_node;
    }
    *head_ref = new_node;
}

void insert_end(struct Node** head_ref, int data) {
    if (*head_ref == NULL) {
        insert_beg(head_ref, data);
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = data;
    new_node->next = *head_ref;
    while (last->next != *head_ref) {
        last = last->next;
    }
    last->next = new_node;
}

void begin_delete(struct Node** head_ref) {
    if (*head_ref == NULL) {
        return;
    }
    struct Node* last = *head_ref;
    struct Node* temp = *head_ref;
    while (last->next != *head_ref) {
        last = last->next;
    }
    *head_ref = temp->next;
    last->next = *head_ref;
    free(temp);
}

void last_delete(struct Node** head_ref) {
    if (*head_ref == NULL) {
        return;
    }
    struct Node* temp = *head_ref, *last;
    while (temp->next != *head_ref) {
        last = temp;
        temp = temp->next;
    }
    last->next = temp->next;
    free(temp);
}

void display(struct Node* head) {
    if (head == NULL) {
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value;
    do {
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete from beginning\n");
        printf("4. Delete from end\n");
        printf("5. Display the list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to insert at beginning: ");
                scanf("%d", &value);
                insert_beg(&head, value);
                break;
            case 2:
                printf("Enter the value to insert at end: ");
                scanf("%d", &value);
                insert_end(&head, value);
                break;
            case 3:
                begin_delete(&head);
                printf("Node deleted from beginning.\n");
                break;
            case 4:
                last_delete(&head);
                printf("Node deleted from end.\n");
                break;
            case 5:
                printf("The circular linked list is: ");
                display(head);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    return 0;
}
