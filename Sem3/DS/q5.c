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

    int main() {
        int ch;
        int v, e;
        struct Node* adj[100];

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
                for(int i = 1; i <= v; i++) {
                    printf("Nodes connected to %d: ", i);
                    struct Node *temp = adj[i];
                    while(temp != NULL) {
                        printf("%d, weight: %d ", temp->data, temp->weight);
                        temp = temp->next;
                    }
                    printf("\n");
                }
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
