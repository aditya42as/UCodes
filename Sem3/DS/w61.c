/*Problem Statement:
Design an algorithm and write a program to implement stack operations using minimum number
 of queues.
Name: Aditya Singh
Section: E1
Roll No: 8
Course: B.Tech(CSE)*/
#include <stdio.h>
void enqueue(int q[], int *rear, int *front, int val, int maxsize) {
    if ((*rear + 1) % maxsize == *front) {
        printf("Queue (Stack) is full\n");
        return;
    }
    if (*front == -1) {
        *front = *rear = 0;
    } else {
        *rear = (*rear + 1) % maxsize;
    }
    q[*rear] = val;
}

int dequeue(int q[], int *rear, int *front, int maxsize) {
    if (*front == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    int val = q[*front];
    if (*front == *rear) {
        *front = *rear = -1;
    } else {
        *front = (*front + 1) % maxsize;
    }
    return val;
}

int isEmpty(int *front) {
    return (*front == -1);
}

int size(int *front, int *rear, int maxsize) {
    if (*front == -1) return 0;
    if (*rear >= *front) return *rear - *front + 1;
    return maxsize - *front + *rear + 1;
}


void push(int q[], int *rear, int *front, int val, int maxsize) {
    int s = size(front, rear, maxsize);
    enqueue(q, rear, front, val, maxsize);

    for (int i = 0; i < s; i++) {
        int temp = dequeue(q, rear, front, maxsize);
        enqueue(q, rear, front, temp, maxsize);
    }
    printf("Stack - ");
    for (int i = *front; i != *rear; i = (i + 1) % maxsize)
        printf("%d ", q[i]);
    printf("%d\n", q[*rear]);
}

void pop(int q[], int *rear, int *front, int maxsize) {
    if (isEmpty(front)) {
        printf("Stack is empty\n");
        return;
    }
    int val = dequeue(q, rear, front, maxsize);
    printf("Element popped from stack : %d\n", val);

    if (!isEmpty(front)) {
        printf("Stack after pop operation : ");
        for (int i = *front; i != *rear; i = (i + 1) % maxsize)
            printf("%d ", q[i]);
        printf("%d\n", q[*rear]);
    }
}

int main() {
    int front = -1, rear = -1;
    int n, ch, val;
    printf("Enter size of queqe: ");
    scanf("%d",&n);
    int q[n];
    printf("Press:\n1 to push\n2 to pop\n3 to find size\n4 to exit\n");
    do {
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                push(q, &rear, &front, val, n);
                break;
            case 2:
                pop(q, &rear, &front, n);
                break;
            case 3:
                printf("Size of stack = %d\n", size(&front, &rear, n));
                break;
            case 4:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid input\n");
        }
    } while (ch != 4);

    return 0;
}
