/*Problem Statement:
Given an array of nonnegative integers, where all numbers occur even number of times except one number which occurs odd number of times. Write an algorithm and a program to find this number. (Time complexity = O(n))
Name: Aditya Singh
Section: E1
Roll No: 8
Course: B.Tech(CSE)*/

#include <stdio.h>
int findOdd(int arr[], int n) {
    int res = 0;
    for (int i = 0; i < n; i++)
        res ^= arr[i];
    return res;
}

int main() {
    int t;
    printf("Test Cases: ");
    scanf("%d", &t);
    int c = 0;
    while(c != t) {
        int n;
        printf("Enter the no. of elements in the array: ");
        scanf("%d", &n);
        int arr[n];
        printf("Enter Elements of the array: \n");
        for(int i = 0; i < n; i++) { 
            scanf("%d", &arr[i]);
        }
        printf("%d\n", findOdd(arr, n));
        c++;
    }
    return 0;
}
