/*Q26.Given a knapsack of maximum .... has maximum value.*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int weight, value;
};

bool cmp(Item a, Item b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> arr(n);

    cout << "Enter weights: " << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i].weight;
    }

    cout << "Enter values: " << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i].value;
    }

    cout << "Enter capacity: ";
    cin >> W;

    sort(arr.begin(), arr.end(), cmp);

    double maxVal = 0;

    cout << "Selected items:" << endl;

    for(int i = 0; i < n; i++) {
        if(W >= arr[i].weight) {
            maxVal += arr[i].value;
            W -= arr[i].weight;
            cout << arr[i].weight << " (full)\n";
        } 
        else {
            double fraction = (double)W / arr[i].weight;
            maxVal += arr[i].value * fraction;
            cout << arr[i].weight << " (" << fraction << " fraction)\n";
            break;
        }
    }

    cout << "Maximum value : " << maxVal;
}