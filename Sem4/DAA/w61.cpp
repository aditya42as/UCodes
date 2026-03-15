/*Q16.  Given a (directed/undirected) graph, design an algorithm and implement it using a program to
find if a path exists between two given vertices or not. */
#include <iostream>
#include <vector>

using namespace std;

bool dfs(int node, int dest, vector<int> &vis, vector<int> adj[]) {
    vis[node] = 1;

    if(node == dest) {
        return true;
    }
    for(auto it : adj[node]) {
        if(!vis[it]) {
            if(dfs(it, dest, vis, adj)) {
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

    int src, dest;
    cin >> src >> dest;

    src--; 
    dest--;

    vector<int> vis(n,0);

    if(dfs(src, dest, vis, adj)) {
        cout<<"Yes Path Exists";
    }
    else {
        cout<<"No Path Exists";
    }
}