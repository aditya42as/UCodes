/*Q3. Given an already sorted array of positive integers, design an algorithm and implement it using a
program to find whether a given key element is present in the sorted array or not. For an array
arr[n], search at the indexes arr[0], arr[2], arr[4],.....,arr[2k] and so on. Once the interval (arr[2k] <
key < arr[ 2k+1] ) is found, perform a linear search operation from the index 2k to find the element
key.
*/
#include <iostream>
using namespace std;

bool search(int arr[], int n, int key, int &count) {
    int prev = -1;
    int next = 1;

    count++;
    if (arr[0] == key) {
        return 1;
    }

    while (next < n && arr[next] <= key) {
        count++;
        prev = next;
        next = 2 * next;
    }

    for (int i = prev; i <= min(n - 1, next); i++) {
        count++;
        if (arr[i] == key) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter key to search: ";
    int key;
    cin >> key;

    int comparisons = 0;

    if (search(arr, n, key, comparisons)) {
        cout << "Key found in the array\n";
    } else {
        cout << "Key not found in the array\n";
    }
    cout << "Comparisons: " << comparisons;
}
