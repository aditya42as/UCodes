/*Q13. Given an unsorted array of alphabets containing duplicate elements. Design an algorithm and
implement it using a program to find which alphabet has maximum number of occurrences and
print it. (Time Complexity = O(n))
*/

#include <iostream>
#include <vector>
using namespace std;

void countSort(vector<char> &arr, int n) {
    vector<int> count(26, 0);
    for (int i = 0; i < n; i++) {
        count[arr[i] - 'a']++;
    }
    int freq = 0;
    char alphabet = '\0';
    for (int i = 0; i < 26; i++) {
        if (count[i] > freq) {
            freq = count[i];
            alphabet = i + 'a';
        }
    }
    if (freq <= 1)
        cout << "No Duplicates Present";
    else {
        cout << "Most repeated alphabet: " << alphabet << endl;
        cout << "Frequency: " << freq << endl;
    }
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<char> arr(n);
    cout << "Enter array: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    countSort(arr, n);
}
