#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int x) {
    struct Node* newNode = malloc(sizeof(struct Node));
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
    return;
}

void dfs(struct Node *adj[], int s, int visited[]) {
    
    printf("%d ", s);
    visited[s] = 1;
    struct Node *temp = adj[s];
    while(temp != NULL) {
        if(visited[temp->data] == 0 ) {
            dfs(adj, temp->data, visited);
        }
        else {
            temp = temp->next;
        }
    }
    return;
}

int main() {
    int v, e;
    printf("Enter no. of vertices and edges: ");
    scanf("%d %d", &v, &e);
    struct Node* adj[v+1];
    
    for(int i = 1; i <= v; i++) {
        adj[i] = NULL;
    }

    printf("Enter graph: \n");
    for(int i = 1; i <= e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj,u,v);
    }

    for(int i = 1; i <= v; i++) {
        printf("Nodes connected to %d: ", i);
        struct Node *temp = adj[i];
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }   

    int queqe[100];
    int rear = 0, front = 0;

    int visited[v+1];
    memset(visited, 0, sizeof(visited));

    int s;
    printf("Enter starting Node: ");
    scanf("%d", &s);

    queqe[rear] = s;
    visited[s] = 1;

    printf("BFS: ");
    while(front <= rear) {
        int f = queqe[front];
        front++;
        printf("%d ", f);
        struct Node *temp = adj[f];
        while(temp != NULL) {
            if(visited[temp->data] == 0) {
                queqe[++rear] = temp->data;
                visited[temp->data] = 1;
                temp = temp->next;
            }
            else{
                temp = temp->next;
            }
        }
    }
    memset(visited, 0, sizeof(visited));
    printf("\nEnter starting Node for DFS: ");
    scanf("%d", &s);

    printf("DFS: ");
    dfs(adj, s, visited);
    printf("\n");
}
