/*Q1. Given an array of nonnegative integers, design a linear algorithm and implement it using a
program to find whether given key element is present in the array or not. Also, find total number
of comparisons for each input case. (Time Complexity = O(n), where n is the size of input)*/

#include <iostream>
using namespace std;
int main() {
    int n, key;
    cout << "Enter size: ";
    cin >> n;
    int arr[n];
    cout << "Enter array: " << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter key to search: ";
    cin >> key;
    int count = 0;
    bool found = false;

    for(int i = 0; i < n; i++) {
        count++;
        if(arr[i] == key) {
            found = true;
            break;
        }
    }

    if(found) {
        cout << "Present " << endl;
        cout << "No. of comparisons: " << count << endl;
    }
    else{
        cout << "Not Present " << endl;
        cout << "No. of comparisons: " << count << endl;
    }
}