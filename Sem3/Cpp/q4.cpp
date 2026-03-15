/*Practical No.4
You are given an array of elements. Now you need to choose the best index of this array. 
An index of the array is called best if the special sum of this index is maximum across 
the special sum of all the other indices. To calculate the special sum for any index you 
pick the first element that is and add it to your sum. Now you pick next two elements 
i.e., and add both of them to your sum. Now you will pick the next elements, and this 
continues 
till the index for which it is possible to pick the elements. Find the best index and in the 
output print its corresponding special sum. Note that there may be more than one best 
index, but you need to only print the maximum special sum. 

Name: Aditya Singh
Section: E1
Roll no. 8*/
#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout<< "Enter elements of the array: "<< endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int bestSum = 0;
    for (int start = 0; start < n; start++) {
        int k = 1, sum = 0, idx = start;
        while (idx + k <= n) {
            for (int j = 0; j < k; j++) {
                sum += arr[idx + j];
            }
            idx += k;
            k++;
        }
        if (sum > bestSum) bestSum = sum;
    }
    cout << "Maximum Special Sum = " << bestSum;
}
