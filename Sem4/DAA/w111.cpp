/*Q31. Given a sequence of matrices, write an algorithm to find most efficient way to multiply these
matrices together. To find the optimal solution, you need to find the order in which these
matrices should be multiplied.
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int matrixChain(vector<int> &p, int n) {
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + p[i] * p[k + 1] * p[j + 1]);
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;

    vector<int> p(n + 1);

    cout << "Enter dimensions:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> p[i + 1];
    }

    cout << matrixChain(p, n);
}