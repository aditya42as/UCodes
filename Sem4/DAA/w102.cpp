/*Q29. Given a long list of tasks. Each task takes specific time to accomplish it and each task has a
deadline associated with it. You have to design an algorithm and implement it using a program to
find maximum number of tasks that can be completed without crossing their deadlines and also
find list of selected tasks.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int time, deadline, index;
};

bool cmp(Job a, Job b) {
    return a.deadline < b.deadline;
}

vector<int> scheduleJobs(vector<Job> &jobs) {
    sort(jobs.begin(), jobs.end(), cmp);

    int curr = 0;
    vector<int> res;

    for(auto j:jobs) {
        if(curr + j.time <= j.deadline) {
            curr += j.time;
            res.push_back(j.index);
        }
    }
    return res;
}

int main() {
    int n;
    cout << "Enter number of tasks: ";
    cin >> n;

    vector<Job> jobs(n);

    cout << "Enter time required:" << endl;
    for(int i=0;i<n;i++) {
        cin >> jobs[i].time;
    }

    cout << "Enter deadlines:" << endl;
    for(int i=0;i<n;i++){
        cin >> jobs[i].deadline;
        jobs[i].index = i+1;
    }

    vector<int> ans = scheduleJobs(jobs);

    cout << "Max number of tasks = " << ans.size() << endl;
    cout << "Selected tasks: ";
    for(int x:ans) {
        cout << x << " ";
    }
}