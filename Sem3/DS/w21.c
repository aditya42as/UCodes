/*Problem Statement:
Given a matrix of size n X n, where every row and every column is sorted in increasing order.
 Write an algorithm and a program to find whether the given key element is present in the matrix
 or not. (Linear time complexity)
Name: Aditya Singh
Section: E1
Roll No: 8
Course: B.Tech(CSE)*/

#include <stdio.h>
int searchMatrix(int n, int mat[n][n], int key) {
    int i = 0, j = n-1;
    while(i < n && j >= 0) {
        if(mat[i][j] == key){
            return 1;
        } 
        else if(mat[i][j] > key) {
            j--;
        }
        else {
            i++;
        }
    }
    return 0;
}

int main() {
    int n, key;
    printf("Enter the no. of rows and columns for the square matrix: ");
    scanf("%d", &n);
    int mat[n][n];
    printf("Enter the elements of the matrix: \n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&mat[i][j]);
        }
    }
    printf("Enter the key to find in the matrix: ");
    scanf("%d",&key);
    if(searchMatrix(n, mat, key))
        printf("Key found\n");
    else
        printf("Key not found\n");
    return 0;
}
