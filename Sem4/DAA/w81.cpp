/* Assume that a project of road construction to connect some cities is given to your friend. Map of
these cities and roads which will connect them (after construction) is provided to him in the form
of a graph. Certain amount of rupees is associated .... cities should be minimum*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int prims(vector<vector<pair<int,int>>> &adj, int source, int n) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<bool> vis(n,false);

    pq.push({0,source});
    int sum=0;

    while(!pq.empty()){
        auto it=pq.top(); pq.pop();
        int node=it.second, wt=it.first;

        if(vis[node]) continue;

        vis[node]=true;
        sum+=wt;

        for(auto x:adj[node]){
            if(!vis[x.first])
                pq.push({x.second,x.first});
        }
    }
    return sum;
}

int main(){
    int n,m;
    cout << "Enter number of nodes and edges: ";
    cin>>n>>m;

    vector<vector<pair<int,int>>> adj(n);

    cout << "Enter edges (u v w):\n";
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    int src;
    cout << "Enter source node: ";
    cin >> src;

    cout<<"Minimum Spanning Weight: "<<prims(adj,src,n);
}