/*Q15. You have been given two sorted integer arrays of size m and n. Design an algorithm and
implement it using a program to find list of elements which are common to both. (Time
Complexity = O(m+n))
*/

#include<iostream>
#include<vector>
using namespace std;

int main() {
    int m;
    cout << "Enter size of arr1: ";
    cin >> m;
    vector<int> arr(m);
    cout << "Enter arr1: " << endl;
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }

    int n; 
    cout << "Enter size for arr2: ";
    cin >> n;
    vector<int> arr1(n);
    cout << "Enter arr2: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    int i = 0, j = 0;
    cout << "Common elements: ";
    while (i < m && j < n) {
        if (arr[i] == arr1[j]) {
            cout << arr[i] << " ";
            i++;
            j++;
        }
        else if (arr[i] < arr1[j]) {
            i++;
        }
        else {
            j++;
        }
    }
}
