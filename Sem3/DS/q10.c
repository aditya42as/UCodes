#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    int weight;
    struct Node *next;
};

struct Node *createNode(int x, int w) {
    struct Node* newNode = malloc(sizeof(struct Node));
    if (!newNode) { perror("malloc"); exit(1); }
    newNode->data = x;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node *adj[], int u, int v, int w) {
    struct Node *newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;
    newNode = createNode(u, w);
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
    int ch;
    int v, e;
    struct Node* adj[100];
    int visited[100];

    printf("1. Create Graph\n2. Insert Graph\n3. Display Graph\n4. Exit\nPress: ");
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
                int u, vv, w;
                scanf ("%d %d %d", &u, &vv, &w);
                addEdge(adj, u, vv, w);
            }
            break;
        case 3:
            memset(visited, 0, sizeof(visited));
            printf("\nEnter starting Node for DFS: ");
            int s;
            scanf("%d", &s);
            printf("DFS: ");
            dfs(adj, s, visited);
            printf("\n");
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
