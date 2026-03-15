/*Q18 Given a directed graph, design an algorithm and implement it using a program to find whether
cycle exists in the graph or not.*/
#include <iostream>
#include <vector>

using namespace std;

bool dfs(int node, vector<int> &vis, vector<int> &pathVis, vector<int> adj[]) {

    vis[node] = 1;
    pathVis[node] = 1;

    for(auto it : adj[node]) {
        if(!vis[it]) {
            if(dfs(it, vis, pathVis, adj)) {
                return true;
            }
        }
        else if(pathVis[it]) {
            return true;
        }
    }
    pathVis[node] = 0;
    return false;
}

bool detectCycle(vector<int> adj[], int n) {

    vector<int> vis(n,0);
    vector<int> pathVis(n,0);

    for(int i=0;i<n;i++) {
        if(!vis[i]) {
            if(dfs(i, vis, pathVis, adj)) {
                return true;
            }
        }
    }

    return false;
}

int main() {

    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> adj[n];

    cout << "Enter adjacency list: " << endl;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            int x;
            cin >> x;
            if(x==1) {
                adj[i].push_back(j);
            }
        }
    }

    if(detectCycle(adj,n)) {
        cout<<"Yes Cycle Exists";
    }
    else {
        cout<<"No Cycle Exists";
    }
}