#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int prims(vector<vector<pair<int,int>>> adj, int source, int nodes) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool>visited(nodes+1, 0);
    
    pq.push({0, source});
    int sum = 0;

    while(!pq.empty()) {
        int node = pq.top().second;
        int wt = pq.top().first;
        pq.pop();

        if(visited[node]) continue;
        visited[node] =true;
        sum += wt;

        for(auto it: adj[node]) {
            int v = it.first;
            int w = it.second;
            if(!visited[v]) {
                pq.push({w,v});
            }

        }
    }
    return sum;
}

int main() {
    int nodes, edges;
    cout << "Enter no. nodes and edges: ";
    cin >> nodes >> edges;

    vector<vector<pair<int,int>>>adj(nodes);

    cout << "Enter graph: ";
    for(int i = 0; i < edges; i++) {
        int src, dest, w;
        cin >> src >> dest >> w;
        adj[src].push_back({dest, w});
        adj[dest].push_back({src, w});
    }

    int source;
    cout << "Enter source node: ";
    cin >> source;

    prims(adj, source, nodes);
}