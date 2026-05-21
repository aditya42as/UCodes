/* Given a directed graph with two vertices ( source and destination). Design an algorithm and
implement it using a program to find the weight of the shortest path from source to destination
with exactly k edges on the path. */
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int solve(vector<vector<int>> &graph, int u, int v, int k, int n) {
    if(k==0 && u==v) return 0;
    if(k==1 && graph[u][v]!=INT_MAX) return graph[u][v];
    if(k<=0) return INT_MAX;

    int res = INT_MAX;

    for(int i=0;i<n;i++) {
        if(graph[u][i]!=INT_MAX) {
            int sub = solve(graph,i,v,k-1,n);
            if(sub!=INT_MAX)
                res = min(res, graph[u][i]+sub);
        }
    }
    return res;
}

int main(){
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(n, INT_MAX));

    cout << "Enter edges (u v w):\n";
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        graph[u][v]=w;
    }

    int u,v,k;
    cout << "Enter source and destination: ";
    cin >> u >> v;

    cout << "Enter value of k: ";
    cin >> k;

    int ans = solve(graph,u,v,k,n);

    if(ans==INT_MAX)
        cout<<"No path of length "<<k<<" is available";
    else
        cout<<"Weight: "<<ans;
}