/*Q30. Given an unsorted array of elements, design an algorithm and implement it using a program to
find whether majority element exists or not. Also find median of the array. A majority element is
an element that appears more than n/2 times, where n is the size of array.*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void majority(vector<int> &arr, int n) {
    int ele = -1;
    int c = 0;

    for(int i = 0; i < n; i++) {
        if(c == 0) {
            ele = arr[i];
            c = 1;
        }
        else if(ele == arr[i]) {
            c++;
        }
        else {
            c--;
        }
    }

    int count = 0;
    for(int i = 0; i < n; i++) {
        if(ele == arr[i]) count++;
    }

    if(count > n/2) {
        cout << "Majority element: " << ele << endl;
    }
    else {
        cout << "no" << endl;
    }

    sort(arr.begin(), arr.end());
    cout << "Median: "<< arr[n/2] << endl;
}
int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    majority(arr, n);
}