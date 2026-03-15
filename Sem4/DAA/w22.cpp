/*Q5. Given a sorted array of positive integers, design an algorithm and implement it using a program
to find three indices i, j, k such that arr[i] + arr[j] = arr[k]. 
*/
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[n];
    cout << "Enter array: " << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Sequences found: " << endl;
    for(int k = n-1; k >= 2; k--) {
    int sum = arr[k];
    int i = 0;
    int j = k-1;
    
    while(i < j) {
        int temp = arr[i] + arr[j];
        if(sum == temp) {
            cout << i << " " << j << " " << k <<  endl;
            break;
        }
        else if(sum < temp) {
            j--;
        }
        else {
            i++;
        }
    }
    }
}