/*Problem Statement:
 Design an algorithm and a program to implement queue using array. The program should
implement following queue operations:
 a) Create() - create a queue
 b) EnQueue(k) - insert an element k into the queue
 c) DeQueue() - delete an element from the queue
 d) IsEmpty() - check if queue is empty or not
 e) Size() - finds the size of the queue
Name: Aditya Singh
Section: E1
Roll No: 8
Course: B.Tech(CSE)*/

#include <stdio.h>

int isEmpty(int *front, int *rear) {
    if (*front == -1 && *rear == -1)
        return 1;
    else
        return 0;
}

int size(int *front, int *rear) {
    if (*front == -1 && *rear == -1)
        return 0;
    else
        return (*rear - *front + 1);
}

void enqueue(int queue[], int *rear, int *front, int value, int maxsize) {
    if (*rear == maxsize - 1) {
        printf("Queue is full\n");
    }
    else if (*rear == -1 && *front == -1) {
        *rear = 0;
        *front = 0;
        queue[*rear] = value;
    }
    else {
        ++*rear;
        queue[*rear] = value;
    }
}

void dequeue(int queue[], int *rear, int *front) {
    if (isEmpty(front, rear)) {
        printf("Queue is empty\n");
    }
    else {
        printf("%d removed from queue\n", queue[*front]);
        if (*front == *rear) {
            *front = -1;
            *rear = -1;
        }
        else {
            ++*front;
        }
    }
}

int Qfront(int queue[], int *rear, int *front) {
    if (isEmpty(front, rear)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue[*front];
}

void display(int queue[], int *rear, int *front) {
    if (isEmpty(front, rear)) {
        printf("Queue is empty\n");
    }
    else {
        for (int i = *front; i <= *rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int n, ch, value;
    printf("Enter size of queue: ");
    scanf("%d", &n);
    int queue[n];
    int front = -1;
    int rear = -1;
printf("\nEnter your choice:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Front\n4. Display\n5. Size\n6. isEmpty\n7. Exit\n");
    do {
        
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            printf("Enter Value: ");
            scanf("%d", &value);
            enqueue(queue, &rear, &front, value, n);
            break;
        case 2:
            dequeue(queue, &rear, &front);
            break;
        case 3:
            value = Qfront(queue, &rear, &front);
            if (value != -1)
                printf("Front element: %d\n", value);
            break;
        case 4:
            display(queue, &rear, &front);
            break;
        case 5:
            printf("Size of queue: %d\n", size(&front, &rear));
            break;
        case 6:
            if (isEmpty(&front, &rear))
                printf("Queue is empty\n");
            else
                printf("Queue is not empty\n");
            break;
        case 7:
            printf("Exiting.\n");
            break;
        default:
            printf("Invalid input\n");
            break;
        }
    } while (ch != 7);

    return 0;
}
