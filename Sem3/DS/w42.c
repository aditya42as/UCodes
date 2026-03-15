/* Problem Statement:
Design an algorithm and a program to implement two stacks by using only one array i.e.
both the stacks should use the same array for push and pop operation. Array should be 
divided in such a manner that space should be efficiently used if one stack contains very 
large number of elements and other one contains only few elements.
Name: Aditya Singh
Section: E1
Roll No: 8
Course: B.Tech(CSE)
*/

#include <stdio.h>
#include <stdlib.h>

void push1(int arr[], int *top1, int *top2, int n, int val) {
    if (*top1 < *top2 - 1) {
        arr[++(*top1)] = val;
    } else {
        printf("Overflow in Stack1\n");
    }
}

void push2(int arr[], int *top1, int *top2, int n, int val) {
    if (*top1 < *top2 - 1) {
        arr[--(*top2)] = val;
    } else {
        printf("Overflow in Stack2\n");
    }
}

int pop1(int arr[], int *top1) {
    if (*top1 >= 0) {
        return arr[(*top1)--];
    } else {
        printf("Underflow in Stack1\n");
        return -1;
    }
}

int pop2(int arr[], int *top2, int n) {
    if (*top2 < n) {
        return arr[(*top2)++];
    } else {
        printf("Underflow in Stack2\n");
        return -1;
    }
}

void display(int arr[], int top1, int top2, int n) {
    printf("Stack1 (bottom -> top): ");
    if (top1 == -1) {
        printf("Empty");
    } else {
        for (int i = 0; i <= top1; i++) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");

    printf("Stack2 (bottom -> top): ");
    if (top2 == n) {
        printf("Empty");
    } else {
        for (int i = n - 1; i >= top2; i--) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main() {
    int n, choice, val;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    int top1 = -1, top2 = n;

    printf("\n1. Push in Stack1\n2. Push in Stack2\n3. Pop from Stack1\n4. Pop from Stack2\n5. Display\n6. Exit\nChoose: ");
    do {
        
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                push1(arr, &top1, &top2, n, val);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                push2(arr, &top1, &top2, n, val);
                break;

            case 3:
                val = pop1(arr, &top1);
                if (val != -1) printf("Popped from Stack1: %d\n", val);
                break;

            case 4:
                val = pop2(arr, &top2, n);
                if (val != -1) printf("Popped from Stack2: %d\n", val);
                break;

            case 5:
                display(arr, top1, top2, n);
                break;

            case 6:
                printf("Exiting\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);

    return 0;
}
