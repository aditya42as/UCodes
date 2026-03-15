#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

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
void dijkstra(struct Node *adj[], int v, int src) {
    int dist[v+1], visited[v+1];
    memset(visited, 0, sizeof(visited));
    for (int i = 1; i <= v; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
    for (int count = 1; count <= v - 1; count++) {
        int u = -1;
        int min = INT_MAX;
        for (int i = 1; i <= v; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }
        if (u == -1) break;
        visited[u] = 1;
        struct Node *p = adj[u];
        while (p) {
            int v = p->data;
            int w = p->weight;
            if (!visited[v] && dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
            p = p->next;
        }
    }
    printf("Shortest distances from %d:\n", src);
    for (int i = 1; i <= v; i++) {
        if (dist[i] == INT_MAX){
            printf("%d -> INF\n", i);
        } 
        else printf("%d -> %d\n", i, dist[i]);
    }
}

int main() {
    int ch, src;
    int v, e;
    struct Node* adj[100];

    printf("1. Create Graph\n2. Insert Graph\n3. Dijkstra\n4. Exit\nPress: ");
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
            printf("Graph Inserted\n");
            break;
        case 3:
            printf("Enter source node: ");
            scanf("%d", &src);
            dijkstra(adj, v, src);
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
