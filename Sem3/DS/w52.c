/*Problem Statement:
Design an algorithm and write a program to reverse a queue.
Name: Aditya Singh
Section: E1
Roll No: 8
Course: B.Tech(CSE)*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void enqueue(int queue[], int *rear, int *front, int value, int maxsize) {
    if (*rear == maxsize - 1) {
        printf("Queue is full\n");
        return;
    }
    if (*front == -1) { 
        *front = 0;
    }
    (*rear)++;
    queue[*rear] = value;
}

void dequeue(int queue[], int *rear, int *front) {
    if (*front == -1 || *front > *rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("%d removed from queue\n", queue[*front]);
    (*front)++;
    if (*front > *rear) { 
        *front = -1;
        *rear = -1;
    }
}


void reverseQueue(int queue[], int *rear, int *front) {
    if (*front == -1 || *front > *rear) {
        return;
    }
    int count = (*rear - *front + 1);
    int *stack = (int *)malloc(count * sizeof(int));
    int top = -1;

    for (int i = *front; i <= *rear; i++) {
        stack[++top] = queue[i];
    }

    int i = *front;
    while (top != -1) {
        queue[i++] = stack[top--];
    }

    free(stack);
}

int main() {
    int n;
    printf("Enter size of queqe: ");
    scanf("%d", &n);

    int *queue = (int *)malloc(n * sizeof(int));
    int front = -1, rear = -1;
    printf("Enter value to insert: ");
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        enqueue(queue, &rear, &front, val, n);
    }

    reverseQueue(queue, &rear, &front);

    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");

    free(queue);
    return 0;
}

