/*Q34. Given two sequences, Design an algorithm and implement it using a program to find the length
of longest subsequence present in both of them. A subsequence is a sequence that appears in the
same relative order, but not necessarily contiguous.*/
#include <iostream>
#include <vector>
using namespace std;

string getLCS(string a, string b) {
    int n = a.size(), m = b.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int i = n, j = m;
    string lcs = "";

    while(i > 0 && j > 0) {
        if(a[i-1] == b[j-1]) {
            lcs = a[i-1] + lcs;
            i--; j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) {
            i--;
        }
        else {
            j--;
        }
    }

    return lcs;
}

int main() {
    string a, b;

    cout << "Enter string 1: ";
    cin >> a;

    cout << "Enter string 2: ";
    cin >> b;

    string lcs = getLCS(a, b);

    cout << "Longest Common Subsequence: " << lcs << endl;
    cout << "length = " << lcs.size() << endl;

    return 0;
}