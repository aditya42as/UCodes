/*Q35.Given a knapsack of maximum capacity w. N items are provided, each having its own value and
weight. Design an algorithm and implement it using a program to find the list of the selected
items such that the final selected content has weight <= w and has maximum value. Here, you
cannot break an item i.e. either pick the complete item or don't pick it. (0-1 property).*/
#include <iostream>
#include <vector>
using namespace std;

void knapsack(vector<int> &wt, vector<int> &val, int W) {
    int n = wt.size();

    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i=1;i<=n;i++){
        for(int w=1;w<=W;w++){
            if(wt[i-1] <= w)
                dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    cout << "Value = " << dp[n][W] << endl;

    int w = W;
    vector<int> selected_wt, selected_val;

    for(int i = n; i > 0; i--) {
        if(dp[i][w] != dp[i-1][w]) {
            selected_wt.push_back(wt[i-1]);
            selected_val.push_back(val[i-1]);
            w -= wt[i-1];
        }
    }

    cout << "Weights selected: ";
    for(int x : selected_wt) cout << x << " ";
    cout << endl;

    cout << "Values of selected weights: ";
    for(int x : selected_val) cout << x << " ";
}

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> wt(n), val(n);

    cout << "Enter weights:" << endl;
    for(int i=0;i<n;i++) cin >> wt[i];

    cout << "Enter values:" << endl;
    for(int i=0;i<n;i++) cin >> val[i];

    cout << "Enter capacity: ";
    cin >> W;

    knapsack(wt, val, W);

    return 0;
}