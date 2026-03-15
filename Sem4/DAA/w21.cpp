/*Q4. Given a sorted array of positive integers containing few duplicate elements, design an algorithm
and implement it using a program to find whether the given key element is present in the array or
not. If present, then also find the number of copies of given key. (Time Complexity = O(log n))*/
#include <iostream>
using namespace std;

int lowerBound(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    int lower = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= key) {
            lower = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return lower;
}

int upperBound(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    int upper = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > key) {
            upper = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return upper;
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[n];
    cout << "Enter array: " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int key;
    cout << "Enter key: ";
    cin >> key;

    int lb = lowerBound(arr, n, key);

    if (lb == -1 || arr[lb] != key) {
        cout << "Key not present";
        return 0;
    }

    int ub = upperBound(arr, n, key);
    if (ub == -1)
        ub = n;

    cout << "Result: " << key << " " << (ub - lb);
}
