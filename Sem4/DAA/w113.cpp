/*Q33. Given a set of elements, you have to partition the set into two subsets such that the sum of
elements in both subsets is same. Design an algorithm and implement it using a program to solve
this problem.*/

#include <iostream>
#include <vector>
using namespace std;

bool canPartition(vector<int> &arr) {
    int sum = 0;
    for (int x : arr) {
        sum += x;
    }
    if (sum % 2) {
        return false;
    }
    int target = sum / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int x : arr) {
        for (int i = target; i >= x; i--) {
            dp[i] = dp[i] || dp[i - x];
        }
    }
    return dp[target];
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (canPartition(arr)) {
        cout << "yes";
    }
    else {
        cout << "no";
    }
}