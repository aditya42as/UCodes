/*Problem Statement:
Given an array of integers, write an algorithm and a program to left rotate the array by specific number of elements.
Name: Aditya Singh
Section: E1
Roll No: 8
Course: B.Tech(CSE)*/
#include <stdio.h>
void leftRotate(int arr[], int n, int k) {
    k = k % n;
    int temp[n];
    int i, j = 0;

    for(i = k; i < n; i++) {
        temp[j++] = arr[i];
    }
    for(i = 0; i < k; i++) {
        temp[j++] = arr[i];
    }
    for(i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}
int main() {
    int t;
    printf("Test Cases: ");
    scanf("%d", &t);
    int c = 0;
    while(c != t) {
    int n, k;
    printf("Enter no. of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements of the array: \n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter value to rotate the elements: ");
    scanf("%d", &k);
    leftRotate(arr, n, k);
    printf("Updated array: \n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n"); 
    c++;
    }
    return 0;
}
