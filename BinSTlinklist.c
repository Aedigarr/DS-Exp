#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(struct Node* root, int data) {
    if (data <= root->data) {
        if (root->left == NULL) {
            root->left = createNode(data);
        } else {
            insert(root->left, data);
        }
    } else {
        if (root->right == NULL) {
            root->right = createNode(data);
        } else {
            insert(root->right, data);
        }
    }
}

void BFS(struct Node* root) {
    if (root == NULL) return;

    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear] = root;
    while (front <= rear) {
        struct Node* current = queue[front];
        front++;
        printf("%d ", current->data);

        if (current->left != NULL) {
            rear++;
            queue[rear] = current->left;
        }

        if (current->right != NULL) {
            rear++;
            queue[rear] = current->right;
        }
    }
}

int main() {
    struct Node* root = createNode(50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Binary Search Tree Traversal: ");
    BFS(root);

    return 0;
}
