/*Q25. Given a graph, Design an algorithm and implement it using a program to implement Floyd
Warshall all pair shortest path algorithm.*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(n, INT_MAX));

    for(int i = 0; i < n; i++) {
        graph[i][i] = 0;
    }

    cout << "Enter edges (u v w):\n";
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(graph[i][k] != INT_MAX && graph[k][j] != INT_MAX) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }

    cout << "Shortest Distance Matrix: " << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(graph[i][j] == INT_MAX){
              cout << "INF ";  
            } 
            else {
                cout << graph[i][j] << " ";
            }
        }
        cout << endl;
    }
}