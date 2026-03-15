#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int x) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node *adj[], int u, int v) {
    struct Node *newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

void BFS(struct Node *adj[], int v) {
    int queqe[100];
    int rear = 0, front = 0;
    int visited[v+1];
    memset(visited, 0, sizeof(visited));
    int q[100];
    int start;
    printf("\nEnter starting node for BFS: ");
    scanf("%d", &start);
    q[rear] = start;
    visited[start] = 1;

    printf("\nBFS: ");
    while (front <= rear) {
        int curr = q[front++];
        printf("%d ", curr);

        struct Node *temp = adj[curr];
        while (temp != NULL) {
            if (!visited[temp->data]) {
                q[++rear] = temp->data;
                visited[temp->data] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
        
}

int main() {
    int ch;
    int v, e;
    struct Node* adj[100];

    printf("1. Create Graph\n2. Insert Graph\n3. BFS Traversal\n4. Exit\nPress: ");
    do{
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            printf("Enter no. of vertices and edges: ");
            scanf("%d %d", &v, &e);
            memset(adj, 0, sizeof(adj));
            break;

        case 2:
            printf("Enter Graph(source,dest,weight):");
            for (int i = 0; i < e; i++) {
                int u, w;
                scanf ("%d %d %d", &u, &w);
                addEdge(adj, u, w);
            }
            printf("Graph Inserted\n");
            break;
        case 3:
            BFS(adj, v);
            break;

        case 4:
            printf("Program exited\n");
            return 0;

        default:
            printf("Invalid Input. Try Again\n");
            break;
        }
    }while(ch != 4);
    
}
