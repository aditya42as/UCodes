#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> bellMan(vector<vector<int>> &edges, int s, int n) {
    vector<int> dist(n, INT_MAX);
    dist[s] = 0;

    for(int i = 0; i < n -1; i++) {
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    return dist;
}

int main() {
    int n, m;
    cout << "Enter no. of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(3));
    vector<vector<int>> adj(n+1);

    for(int i = 0; i < m; i++) {
        int v,u,w;
        cin >> u >> v >> w;
         
    }



}