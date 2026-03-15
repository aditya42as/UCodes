/*Problem Statement:
Design an algorithm and write a program to implement queue operations using minimum number
 of stacks.
Name: Aditya Singh
Section: E1
Roll No: 8
Course: B.Tech(CSE)*/
#include <stdio.h>

int *s1, *s2;
int top1 = -1, top2 = -1;
int n;

void push(int s[], int *top, int val) {
    if (*top == n - 1) {
        printf("Stack overflow\n");
        return;
    }
    s[++(*top)] = val;
}

int pop(int s[], int *top) {
    if (*top == -1) {
        return -1;
    }
    return s[(*top)--];
}

int isEmpty(int top) {
    return (top == -1);
}

int size() {
    return (top1 + 1) + (top2 + 1);
}

void enqueue(int val) {
    if (top1 == n - 1) {
        printf("Queue is full\n");
        return;
    }
    push(s1, &top1, val);
    printf("%d enqueued to queue\n", val);
}

int dequeue() {
    if (isEmpty(top1) && isEmpty(top2)) {
        printf("Queue is empty\n");
        return -1;
    }
    if (isEmpty(top2)) {
        while (!isEmpty(top1)) {
            int temp = pop(s1, &top1);
            push(s2, &top2, temp);
        }
    }
    int val = pop(s2, &top2);
    printf("%d dequeued from queue\n", val);
    return val;
}

void display() {
    if (isEmpty(top1) && isEmpty(top2)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = top2; i >= 0; i--) {
        printf("%d ", s2[i]);
    }
    for (int i = 0; i <= top1; i++) {
        printf("%d ", s1[i]);
    }
    printf("\n");
}

int main() {
    int ch, val;
    printf("Enter size of queue: ");
    scanf("%d", &n);
    int stack1[n], stack2[n];
    s1 = stack1;
    s2 = stack2;
    printf("\nPress:\n1 to Enqueue\n2 to Dequeue\n3 to Find Size\n4 to Display\n5 to Exit\n");
    do {
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printf("Size of queue = %d\n", size());
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid input\n");
        }
    } while (ch != 5);

    return 0;
}
