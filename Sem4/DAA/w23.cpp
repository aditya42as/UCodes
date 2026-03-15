/*Q6. Given an array of nonnegative integers, design an algorithm and a program to count the number
of pairs of integers such that their difference is equal to a given key, K.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cout << "Enter size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter key: ";
    cin >> k;

    sort(arr.begin(), arr.end());

    int i = 0, j = 1;
    int count = 0;

    while (i < n && j < n) {
        if (i == j) {
            j++;
            continue;
        }

        int diff = arr[j] - arr[i];

        if (diff == k) {
            count++;
            i++;
            j++;
        }
        else if (diff < k) {
            j++;
        }
        else {
            i++;
        }
    }
    cout << "Count: " << count  << endl;
}
