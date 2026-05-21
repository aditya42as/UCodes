/* Assume that same road construction .... cost.
Design an algorithm and implement it using a program to find the maximum budget  required for
the project*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findpar(int u, vector<int> &par){
    if(par[u] == u) {
        return u;
    }
    return par[u] = findpar(par[u], par);
}

void unionSet(int u, int v, vector<int> &par, vector<int> &rank){
    int pu = findpar(u, par);
    int pv = findpar(v, par);

    if(pu == pv) return;

    if(rank[pu] < rank[pv]) {
        par[pu] = pv;
    }
    else if(rank[pu] > rank[pv]) {
        par[pv] = pu;
    }
    else{
        par[pv] = pu;
        rank[pu]++;
    }
}

int main(){
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin>> n >> m;

    vector<vector<int>> edges;

    cout << "Enter edges (u v w):" << endl;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w,u,v});
    }

    sort(edges.rbegin(), edges.rend());

    vector<int> par(n), rank(n,0);
    for(int i = 0; i < n; i++){
        par[i] = i;
    }

    int sum = 0;


    for(auto e : edges) {
        int w=e[0], u=e[1], v=e[2];

        if(findpar(u,par) != findpar(v,par)){
            sum += w;
            unionSet(u, v, par, rank);
        }
    }

    cout << "Maximum Spanning Weight: " << sum;
}