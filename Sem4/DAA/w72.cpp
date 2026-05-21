/* Design an algorithm and implement it using a program to solve previous question's problem
using Bellman- Ford's shortest path algorithm*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> bellMan(vector<vector<int>> &edges, int s, int n, vector<int> &parent) {
    vector<int> dist(n, INT_MAX);
    dist[s] = 0;

    for(int i = 0; i < n - 1; i++) {
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u; 
            }
        }
    }
    return dist;
}


void printPath(int node, vector<int> &parent) {
    if(node == -1) return;
    printPath(parent[node], parent);
    cout << node << " ";
}

int main() {
    int n, m;
    cout << "Enter no. of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> edges;

    cout << "Enter edges (u v w):\n";
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int src;
    cout << "Enter source node: ";
    cin >> src;

    vector<int> parent(n, -1);

    vector<int> dist = bellMan(edges, src, n, parent);

    cout << "\nShortest Paths:\n";
    for(int i = 0; i < n; i++) {
        cout << "Node " << i << " : ";

        if(dist[i] == INT_MAX) {
            cout << "No path\n";
            continue;
        }

        printPath(i, parent);
        cout << ": " << dist[i] << endl;
    }
}