/*Q27. Given an array of elements. Assume arr[i] represents the size of file i. Write an algorithm and a
program to merge all these files into single file with minimum computation*/
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cout << "Enter number of files: ";
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;

    cout << "Enter file sizes: " << endl;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }

    int cost = 0;

    while(pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();

        int sum = a + b;
        cost += sum;

        pq.push(sum);
    }

    cout << "Minimum computation cost: " << cost;
}