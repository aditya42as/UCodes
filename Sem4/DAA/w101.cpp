/*Q28. Given a list of activities with their starting time and finishing time. Your goal is to select
maximum number of activities that can be performed by a single person such that selected
activities must be non-conflicting. Any activity is said to be non-conflicting if starting time of an
activity is greater than or equal to the finishing time of the other activity. Assume that a person
can only work on a single activity at a time.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Activity {
    int start, finish, index;
};
bool cmp(Activity a, Activity b) {
    return a.finish < b.finish;
}
vector<int> activitySelection(vector<Activity> &arr) {
    sort(arr.begin(), arr.end(), cmp);
    vector<int> res;
    res.push_back(arr[0].index);
    int last = arr[0].finish;
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i].start >= last) {
            res.push_back(arr[i].index);
            last = arr[i].finish;
        }
    }
    return res;
}
int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;
    vector<Activity> arr(n);
    cout << "Enter start times:" << endl;
    for(int i=0;i<n;i++) cin >> arr[i].start;
    cout << "Enter finish times:" << endl;
    for(int i=0;i<n;i++){
        cin >> arr[i].finish;
        arr[i].index = i+1;
    }
    vector<int> ans = activitySelection(arr);
    cout << "No. of non-conflicting activities: " << ans.size() << endl;
    cout << "Selected activities: ";
    for(int x:ans) cout << x << " ";
}