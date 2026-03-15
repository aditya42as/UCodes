/*Problem Statement:
Given a boolean matrix (contains only 0 and 1) of size m X n where each row is sorted, write an
 algorithm and a program to find which row has maximum number of 1's. (Linear time
 complexity)
Name: Aditya Singh
Section: E1
Roll No: 8
Course: B.Tech(CSE)*/
#include <stdio.h>
int rowWithMax1s(int m, int n, int mat[m][n]) {
    int maxRow = -1, j = n-1;
    for(int i=0;i<m;i++) {
        while(j >= 0 && mat[i][j] == 1) {
            j--; 
            maxRow = i;
        }
    }
    return maxRow;
}

int main() {
    int m,n;
    printf("Enter the no. of rows and columns in the matrix: ");
    scanf("%d %d",&m, &n);
    int mat[m][n];
    printf("Enter elements of the matrix \n");
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&mat[i][j]);
        }
    }
    int row = rowWithMax1s(m,n,mat);
    if(row==-1) {
        printf("No 1s in matrix\n");
    }
    else {
        printf("%d\n",row);
    }
    return 0;
}
