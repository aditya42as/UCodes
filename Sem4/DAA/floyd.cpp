#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void floyd(vector<vector<int>> &mat, int nodes) {
    for(int k = 0; k < nodes; k++) {
        for(int i = 0; i < nodes; i++) {
            for(int j = 0; j < nodes; j++) {
                if(mat[i][k] != INT_MAX && mat[k][j] != INT_MAX) {
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
    }
}

int main() {
    int nodes,edges;
    cin >> nodes >> edges;
    vector<vector<int>>graph(nodes, vector<int>(nodes,-1));
    for(int i = 0; i < edges; i++) {
        int src ,dest, weight;
        cin >> src >> dest >> weight;
        graph[src][dest] =weight;
    }
    for(int i = 0; i < nodes; i++) {
        graph[i][i] == 0;
    }
    
    for(int i = 0;i < nodes; i++) {
        for(int j = 0; j < nodes; j++) {
            if(graph[i][j] == -1) {
                graph[i][j] = INT_MAX;
            }
        }
    }

    floyd(graph, nodes);
}