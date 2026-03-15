#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int u, v, w;
};

void swap(struct Edge *a, struct Edge *b) {
    struct Edge t = *a;
    *a = *b;
    *b = t;
}

void heapify_down(struct Edge heap[], int size, int i) {
    int left = 2*i + 1;
    int right = 2*i + 2;
    int smallest = i;

    if (left < size && heap[left].w < heap[smallest].w)
        smallest = left;
    if (right < size && heap[right].w < heap[smallest].w)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify_down(heap, size, smallest);
    }
}

void heapify_up(struct Edge heap[], int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent].w > heap[i].w) {
            swap(&heap[parent], &heap[i]);
            i = parent;
        } else break;
    }
}

void push(struct Edge heap[], int *size, struct Edge e) {
    heap[*size] = e;
    heapify_up(heap, *size);
    (*size)++;
}

struct Edge pop(struct Edge heap[], int *size) {
    struct Edge m = heap[0];
    heap[0] = heap[--(*size)];
    heapify_down(heap, *size, 0);
    return m;
}

int findParent(int parent[], int x) {
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent, parent[x]);
}

void unionSet(int parent[], int rank[], int a, int b) {
    a = findParent(parent, a);
    b = findParent(parent, b);

    if (a == b) return;

    if (rank[a] < rank[b]) parent[a] = b;
    else if (rank[b] < rank[a]) parent[b] = a;
    else {
        parent[b] = a;
        rank[a]++;
    }
}

int main() {
    int choice;
    int v = 0, e = 0;
    struct Edge *edges = NULL;

    printf("1. Create Graph\n");
    printf("2. Insert Graph\n");
    printf("3. Run Kruskal MST\n");
    printf("4. Exit\n");
    printf("Press: ");

    do {
        scanf("%d", &choice);

        switch (choice) {

            case 1: {
                if (edges) {
                    free(edges);
                    edges = NULL;
                    v = 0;
                    e = 0;
                }

                printf("Enter number of vertices and edges: ");
                scanf("%d %d", &v, &e);

                edges = malloc(sizeof(struct Edge) * e);

                printf("Graph created\n");
                break;
            }

            case 2: {
                if (!edges) {
                    printf("Create graph first\n");
                    break;
                }

                printf("Enter edges (u v w):\n");
                for (int i = 0; i < e; i++) {
                    scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
                }

                printf("Edges inserted\n");
                break;
            }

            case 3: {
                struct Edge heap[1000];
                int heapSize = 0;

                for (int i = 0; i < e; i++) {
                    push(heap, &heapSize, edges[i]);
                }

                int parent[100], rank[100] = {0};
                for (int i = 1; i <= v; i++) parent[i] = i;

                int count = 0;
                int total = 0;

                printf("Edges in MST:\n");

                while (heapSize > 0 && count < v - 1) {
                    struct Edge curr = pop(heap, &heapSize);
                    int pu = findParent(parent, curr.u);
                    int pv = findParent(parent, curr.v);

                    if (pu != pv) {
                        unionSet(parent, rank, pu, pv);
                        printf("%d - %d (w=%d)\n", curr.u, curr.v, curr.w);
                        total += curr.w;
                        count++;
                    }
                }

                if (count != v - 1)
                    printf("MST not possible\n");
                else
                    printf("Total weight of MST: %d\n", total);

                break;
            }

            case 4:
                printf("Exiting\n");
                return 0;

            default:
                printf("Invalid Input\n");
                break;
        }

    } while (choice != 4);

    return 0;
}
