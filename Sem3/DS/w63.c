#include <stdio.h>

void enqueue(int cq[], int *front, int *rear, int value, int maxsize) {
    if ((*front == 0 && *rear == maxsize - 1) || (*rear + 1) % maxsize == *front) {
        printf("Circular Queue is full\n");
    } else {
        if (*front == -1) {
            *front = 0;
            *rear = 0;
        } else {
            *rear = (*rear + 1) % maxsize;
        }
        cq[*rear] = value;
    }
}

void dequeue(int cq[], int *front, int *rear, int maxsize) {
    if (*front == -1) {
        printf("Circular Queue is empty\n");
    } else {
        printf("%d removed from queue\n", cq[*front]);
        if (*front == *rear) {
            *front = -1;
            *rear = -1;
        } else {
            *front = (*front + 1) % maxsize;
        }
    }
}

void display(int cq[], int *front, int *rear, int maxsize) {
    if (*front == -1) {
        printf("Circular Queue is empty\n");
    } else {
        int i = *front;
        while (1) {
            printf("%d ", cq[i]);
            if (i == *rear) {
                break;
            }
            i = (i + 1) % maxsize;
        }
        printf("\n");
    }
}

int IsEmpty(int *front, int *rear) {
    if (*front == -1) {
        printf("Circular Queue is empty\n");
        return 1;
    } else {
        printf("Circular Queue is not empty\n");
        return 0;
    }
}

int Front(int cq[], int *front, int *rear) {
    if (*front == -1) {
        printf("Circular Queue is empty\n");
        return -1;
    } else {
        printf("Front item: %d\n", cq[*front]);
        return cq[*front];
    }
}

int Rear(int cq[], int *front, int *rear) {
    if (*rear == -1) {
        printf("Circular Queue is empty\n");
        return -1;
    } else {
        printf("Rear item: %d\n", cq[*rear]);
        return cq[*rear];
    }
}

int main() {
    int n, ch, value;
    printf("Enter size of circular queue: ");
    scanf("%d", &n);
    int cq[n];
    int front = -1, rear = -1;
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n5. IsEmpty\n6. Front\n7. Rear\n");
    do {
        
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(cq, &front, &rear, value, n);
                break;
            case 2:
                dequeue(cq, &front, &rear, n);
                break;
            case 3:
                display(cq, &front, &rear, n);
                break;
            case 4:
                printf("Exiting\n");
                break;
            case 5:
                IsEmpty(&front, &rear);
                break;
            case 6:
                Front(cq, &front, &rear);
                break;
            case 7:
                Rear(cq, &front, &rear);
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (ch != 4);

    return 0;
}
