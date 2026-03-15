/*Problem Statement:
Given an array of integers, write an algorithm and a program to left rotate the array by specific number of elements.
Name: Aditya Singh
Section: E1
Roll No: 8
Course: B.Tech(CSE)*/

#include <stdio.h>
int minDistance(int arr[], int n, int a, int b) {
    int prev = -1, minDist = n;
    for (int i = 0; i < n; i++) {
        if (arr[i] == a || arr[i] == b) {
            if (prev != -1 && arr[prev] != arr[i]) {
                if (i - prev < minDist) 
                    minDist = i - prev;
            }
            prev = i;
        }
    }
    if (minDist == n) {
        return -1;
    } 
    else {
        return minDist;
    }
}

int main() {
    int t;
    printf("Test Cases: ");
    scanf("%d", &t);
    int c = 0;
    while(c != t) {
        int n, a, b;
        printf("Enter the no. of elements in the array: ");
        scanf("%d", &n);
        int arr[n];
        printf("Enter elements of the array: \n");
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        printf("Enter the value of a and b: ");
        scanf("%d %d", &a, &b);
        int ans = minDistance(arr, n, a, b);
        if(ans == -1) {
            printf("a or b not present in array\n");
        }
        else {
            printf("%d\n", ans);
        }
        c++;
    }
    return 0;
}
