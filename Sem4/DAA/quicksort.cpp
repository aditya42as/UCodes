#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition(vector<int> &arr, int low, int high, int &comp, int &swaps) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        comp++;
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            swaps++;
        }
    }
    swap(arr[i+1], arr[high]);
    swaps++;
    return i+1;

}
void quickSort(vector<int> &arr, int low, int high, int &comp, int &swaps) {
    if (low < high) {
        int pi = partition(arr, low, high, comp, swaps);
        quickSort(arr, low, pi - 1, comp, swaps);
        quickSort(arr, pi + 1, high, comp, swaps);
    }
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array: " << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int comp = 0, swaps = 0;
    quickSort(arr, 0, n - 1, comp, swaps);
    cout << "sorted array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Comparisons: " << comp << endl;
    cout << "Swaps: " << swaps << endl;

}