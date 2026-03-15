/*Problem Statement:
Given a matrix of size n X n containing positive integers, write an algorithm and a program to
 rotate the elements of matrix in clockwise direction
Name: Aditya Singh
Section: E1
Roll No: 8
Course: B.Tech(CSE)*/
#include <stdio.h>
void rotate(int n, int mat[n][n]) {
    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n/2;j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[i][n-j-1];
            mat[i][n-j-1] = temp;
        }
    }
}

int main() {
    int n;
    printf("Enter the n. of elements in the array: ");
    scanf("%d",&n);
    int mat[n][n];
    printf("Enter the elements of the array: \n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&mat[i][j]);
        }
    }
    rotate(n, mat);
    printf("Updated matrix: \n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
