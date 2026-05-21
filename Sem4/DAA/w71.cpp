/*Q19. After end term examination, Akshay .... in minimum time. Akshay has
developed the program that implements Dijkstra’s algorithm but not sure about correctness of
results.*/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void dijkstra(vector<vector<pair<int,int>>> &adj, int n, int src) {
    vector<int> dist(n, INT_MAX), parent(n, -1);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(d > dist[u]) continue;

        for(auto it : adj[u]) {
            int v = it.first, w = it.second;

            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "\nShortest Paths:\n";
    for(int i=0;i<n;i++) {
        cout << "Node " << i << " : " << dist[i] << endl;
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n);

    cout << "Enter edges (u v w):\n";
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    int src;
    cout << "Enter source node: ";
    cin >> src;

    dijkstra(adj,n,src);
}