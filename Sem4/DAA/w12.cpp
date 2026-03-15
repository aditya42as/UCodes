/*Q2. Given an already sorted array of positive integers, design an algorithm and implement it using a
program to find whether given key element is present in the array or not. Also, find total number
of count for each input case. (Time Complexity = O(nlogn), where n is the size of input).
*/
#include <iostream>
using namespace std;
int main() {
    int n, key;
    cout << "Enter size: ";
    cin >> n;
    int arr[n];
    cout << "Enter array: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter key to search: ";
    cin >> key;

    int low = 0, high = n - 1;
    int count = 0;
    bool found = false;

    while (low <= high) {
        count++;
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            found = true;
            break;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if (found) {
        cout << "Present " << endl << count << endl;
    }
    else {
        cout << "Not Present "<< endl << count << endl;
    }
}

