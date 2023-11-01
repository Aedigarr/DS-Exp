#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

struct AdjList {
    struct AdjListNode* head;
};

struct Graph {
    int V;
    struct AdjList* array;
};

struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));

    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void DFSUtil(int v, int visited[], struct Graph* graph) {
    visited[v] = 1;
    printf("%d ", v);

    struct AdjListNode* crawl = graph->array[v].head;
    while (crawl != NULL) {
        if (!visited[crawl->dest])
            DFSUtil(crawl->dest, visited, graph);
        crawl = crawl->next;
    }
}

void DFS(struct Graph* graph, int start) {
    int* visited = (int*)calloc(graph->V, sizeof(int));
    DFSUtil(start, visited, graph);
    free(visited);
}

void BFS(struct Graph* graph, int start) {
    int visited[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear] = start;
    while (front <= rear) {
        int current = queue[front++];
        printf("%d ", current);
        
        struct AdjListNode* temp = graph->array[current].head;
        while (temp) {
            if (!visited[temp->dest]) {
                visited[temp->dest] = 1;
                queue[++rear] = temp->dest;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printf("DFS Traversal: ");
    DFS(graph, 0);
    printf("\n");
    printf("BFS Traversal: ");
    BFS(graph, 0);
    printf("\n");

    return 0;
}