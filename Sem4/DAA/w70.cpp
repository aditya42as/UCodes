#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;



void dijkstra(vector<vector<pair<int, int>>> &adj, int nodes, int src)
{
    vector<int> dist(nodes, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        int curr = pq.top().first;
        int node = pq.top().second;
        pq.pop();


        if (curr > dist[node])  {
            continue;
        }
        for (auto it : adj[node])
        {
            int destination = it.first;
            int weight = it.second;

            if (curr + weight < dist[destination])
            {
                dist[destination] = curr + weight;
                pq.push({dist[destination], destination});
            }
        }
    }

    cout << "\nResults:\n";
    for (int i = 0; i < nodes; i++)
    {
        if (i == src) {
            continue;
        }
        if (dist[i] == INT_MAX)
            cout << "Node " << i << " is unreachable\n";
        else
            cout << "From " << src << " to node " << i << " : " << dist[i] << endl;
    }
}

int main()
{
    int node, edge;

    cout << "Enter no. of nodes and edges: ";
    cin >> node >> edge;

    vector<vector<pair<int, int>>> adj(node);

    cout << "Enter graph (src dest weight):\n";
    for (int i = 0; i < edge; i++)
    {
        int src, dest, weight;
        cin >> src >> dest >> weight;

        adj[src].push_back({dest, weight});
        adj[dest].push_back({src, weight});
    }

    int source;
    cout << "Enter source node: ";
    cin >> source;

    dijkstra(adj, node, source);

}