#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int findpar(int u, vector<int> par) {
    if(par[u] == u) {
        return u;
    }
    return par[u] = findpar(par[u], par);
}

void unionSet(int u, int v, vector<int> &rank, vector<int> &par) {
    int pu = findpar(u, par);
    int pv = findpar(v, par);
    if (rank[pu] < rank[pv]) {
        par[pu] = pv;
    }
    else if(rank[pu] > rank[pv]) {
        par[pv] = pu;
    }
    else {
        par[pu] = pu;
        rank[pv]++;
    }
}

void kruskal(vector<vector<int>> edges, vector<int> par, vector<int> rank) {
    sort(edges.begin(), edges.end());
    int sum = 0;
    for(auto it : edges) {
        int w  =it[0];
        int u = it[1];
        int v = it[2];
        if(findpar(u, par) != findpar(u, par)) {
            sum += w;
            unionSet(u, v, par, rank);
            cout << u << v;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> rank(n,0);
    vector<int> par(n);

    for(int i = 0; i < n; i++) {
        par[i] = i;
    }

    for(int i =0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        unionSet(u,v,rank,par); 
    }

}