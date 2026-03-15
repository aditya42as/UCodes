#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &nums, int n) {
    int flag = 0;
    for(int i = 0; i < n -1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(nums[j] > nums[j+1]) {
                flag = 1;
                swap(nums[j], nums[j+1]);
            }
        }
        if(flag == 0) {
            break;
        }
    }

    cout << "Bubble Sort: ";
    for(int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

}

void insertionSort(vector<int> &nums, int n) {
    
}

void selectionSort(vector<int> &nums, int n) {
    for(int i = 0; i < n- 1; i++) {
        int idx = i;
        for(int j = i+1; j < n; j++){
            if(nums[idx] > nums[j]) {
                idx = j;
            }
        }
        swap(nums[i], nums[idx]);
    }

    cout << "Selection Sort: ";
    for(int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: " << endl;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    bubbleSort(nums, n);
    cout << endl;

    selectionSort(nums, n);
    cout << endl;


}