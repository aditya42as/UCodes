/*Problem Statement:
Design an algorithm and write a program to implement Deque i.e. double ended queue. Double
 ended queue is a queue in which insertion and deletion can be done from both ends of the queue.
 The program should implement following operations:
 a) insertFront() - insert an element at the front of Deque
b)insertEnd() - insert an element at the end of Deque
 c) deleteFront() - delete an element from the front of Deque
 d)deleteEnd() - delete an element from the end of Deque
 e) isEmpty() - checks whether Deque is empty or not
 f)isFull() - checks whether Deque is full or not
 g)printFront() - print Deque from front
 h)printEnd() - print Deque from end
Name: Aditya Singh
Section: E1
Roll No: 8
Course: B.Tech(CSE)*/
#include <stdio.h>

void insertFront(int dq[], int *front, int *rear, int val, int size) {
    if ((*front == 0 && *rear == size - 1) || (*front == *rear + 1)) {
        printf("Deque is full\n");
        return;
    }
    if (*front == -1) { 
        *front = *rear = 0;
    } else if (*front == 0) {
        *front = size - 1;
    } else {
        (*front)--;
    }
    dq[*front] = val;
}

void insertEnd(int dq[], int *front, int *rear, int val, int size) {
    if ((*front == 0 && *rear == size - 1) || (*front == *rear + 1)) {
        printf("Deque is full\n");
        return;
    }
    if (*front == -1) { 
        *front = *rear = 0;
    } else if (*rear == size - 1) {
        *rear = 0;
    } else {
        (*rear)++;
    }
    dq[*rear] = val;
}

void deleteFront(int dq[], int *front, int *rear, int size) {
    if (*front == -1) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deleted from front: %d\n", dq[*front]);
    if (*front == *rear) {
        *front = *rear = -1;
    } else if (*front == size - 1) {
        *front = 0;
    } else {
        (*front)++;
    }
}

void deleteEnd(int dq[], int *front, int *rear, int size) {
    if (*front == -1) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deleted from end: %d\n", dq[*rear]);
    if (*front == *rear) {
        *front = *rear = -1;
    } else if (*rear == 0) {
        *rear = size - 1;
    } else {
        (*rear)--;
    }
}

void printFront(int dq[], int front, int rear) {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }
    printf("Front element: %d\n", dq[front]);
}

void printEnd(int dq[], int front, int rear) {
    if (rear == -1) {
        printf("Deque is empty\n");
        return;
    }
    printf("End element: %d\n", dq[rear]);
}

int isEmpty(int front) {
    return (front == -1);
}

int isFull(int front, int rear, int size) {
    return ((front == 0 && rear == size - 1) || (front == rear + 1));
}

void display(int dq[], int front, int rear, int size) {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    while (1) {
        printf("%d ", dq[i]);
        if (i == rear) break;
        i = (i + 1) % size;
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter size of deque: ");
    scanf("%d", &size);

    int dq[size];
    int front = -1, rear = -1, ch, val;
     printf("\nPress:\n");
        printf("1 Insert Front\n2 Insert End\n3 Delete Front\n4 Delete End\n");
        printf("5 Display\n6 Print Front Element\n7 Print End Element\n");
        printf("8 Check isEmpty\n9 Check isFull\n10 Exit\n");
    do {
       
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertFront(dq, &front, &rear, val, size);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insertEnd(dq, &front, &rear, val, size);
                break;
            case 3:
                deleteFront(dq, &front, &rear, size);
                break;
            case 4:
                deleteEnd(dq, &front, &rear, size);
                break;
            case 5:
                display(dq, front, rear, size);
                break;
            case 6:
                printFront(dq, front, rear);
                break;
            case 7:
                printEnd(dq, front, rear);
                break;
            case 8:
                if (isEmpty(front))
                    printf("Deque is empty\n");
                else
                    printf("Deque is not empty\n");
                break;
            case 9:
                if (isFull(front, rear, size))
                    printf("Deque is full\n");
                else
                    printf("Deque is not full\n");
                break;
            case 10:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (ch != 10);

    return 0;
}
