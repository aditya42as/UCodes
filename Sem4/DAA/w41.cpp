/*Q10. Given an unsorted array of integers, design an algorithm and implement it using a program to
sort an array of elements by dividing the array into two subarrays and combining these subarrays
after sorting each one of them. Your program should also find number of comparisons and
inversions during sorting the array.*/

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high, int &comp, int &inversions) {

    int n1 = mid - low + 1;
    int n2 = high - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[low + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2) {
        comp++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            inversions = inversions + (n1 - i);  
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(vector<int> &arr, int low, int high, int &comp, int &inversions) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid, comp, inversions);
        mergeSort(arr, mid + 1, high, comp, inversions);
        merge(arr, low, mid, high, comp, inversions);
    }
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array: " << endl;
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int comp = 0, inversions = 0;

    mergeSort(nums, 0, n - 1, comp, inversions);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    cout << "Comparisons: " << comp << endl;
    cout << "Inversions: " << inversions << endl;

}
