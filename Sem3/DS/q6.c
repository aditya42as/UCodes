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

int dfs(struct Node *adj[], int cur, int src, int visited[], int degree[], int path[], int depth) {
    visited[cur] = 1;
    path[depth] = cur;
    if (cur != src && degree[cur] == 1) {
        for (int i = 0; i <= depth; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
        return 1;
    }
    struct Node *temp = adj[cur];
    while (temp != NULL) {
        if (!visited[temp->data]) {
            if (dfs(adj, temp->data, src, visited, degree, path, depth + 1)) {
                return 1;
            }
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    int ch,src;
    int v = 0, e = 0;
    struct Node *adj[100];
    int degree[100] = {0};

    printf("1. Create Graph\n2. Insert Edges\n3. Find Store (DFS)\n4. Exit\nPress: ");
    do {
        scanf("%d", &ch);

        switch (ch) {

            case 1:
                printf("Enter no. of vertices and edges: ");
                scanf("%d %d", &v, &e);
                memset(adj, 0, sizeof(adj));
                memset(degree, 0, sizeof(degree));
                printf("Graph created for %d vertices and %d edges.\n", v, e);
                break;

            case 2: 
                printf("Enter Edges (u v):\n");
                for (int i = 0; i < e; i++) {
                    int u, w;
                    scanf("%d %d", &u, &w);
                    addEdge(adj, u, w);
                    degree[u]++;
                    degree[w]++;
                }
                printf("Graph Inserted\n");
                break;

            case 3:
                
                printf("Enter starting node (house): ");
                scanf("%d", &src);
                int visited[100] = {0};
                int path[100];
                printf("Path to store: ");
                int found = dfs(adj, src, src, visited, degree, path, 0);
                if (!found)
                    printf("No store reachable from %d\n", src);
                break;

            case 4:
                printf("Program exited.\n");
                return 0;

            default:
                printf("Invalid Input. Try Again\n");
                break;
        }

    } while (ch != 4);

    return 0;
}
