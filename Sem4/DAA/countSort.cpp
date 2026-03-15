#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int maxed(vector<int> &arr, int n) {
    int m = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] > m) {
            m = arr[i];
        }
    }
    return m;
}

void countSort(vector<int> &arr, int n) {
    int m = maxed(arr, n);
    vector<int> count(m+1, 0);
    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    for(int i = 1; i <= m; i++) {
        count[i] = count[i] + count[i-1];
    }
    for(int j = n-1; j >= 0; j--) {
        ans[count[arr[j]]-1] = arr[j];
        count[arr[j]]--;
    }
    for(int i = 0; i < n; i++) {
        arr[i] = ans[i];
    }
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array: " << endl;
    for(int i=0; i < n; i++) {
        cin >> arr[i];
    }

    countSort(arr,n);
    cout << "sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}