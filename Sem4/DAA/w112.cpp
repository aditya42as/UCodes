/*Q32.Given a set of available types of coins. Let suppose you have infinite supply of each type of coin.
For a given value N, you have to Design an algorithm and implement it using a program to find
number of ways in which these coins can be added to make sum value equals to N. */
#include <iostream>
#include <vector>
using namespace std;

int coinChange(vector<int> &coins, int sum) {
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;

    for (int c : coins) {
        for (int i = c; i <= sum; i++) {
            dp[i] += dp[i - c];
        }
    }
    return dp[sum];
}

int main() {
    int n;
    cout << "Enter number of coins: ";
    cin >> n;

    vector<int> coins(n);

    cout << "Enter coin values:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    int sum;
    cout << "Enter target sum: ";
    cin >> sum;

    cout << coinChange(coins, sum);
}