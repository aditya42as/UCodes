/* Given a graph, design an algorithm and implement it using a program to find if a graph is
bipartite or not.*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool checkBipartite(vector<int> adj[], int n) {

    vector<int> color(n,-1);

    for(int i=0;i<n;i++) {

        if(color[i]==-1) {

            queue<int> q;
            q.push(i);
            color[i] = 0;

            while(!q.empty()) {

                int node = q.front();
                q.pop();

                for(auto it : adj[node]) {
                    if(color[it]==-1) {
                        color[it] = 1 - color[node];
                        q.push(it);
                    }
                    else if(color[it]==color[node]) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

int main() {

    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> adj[n];

    cout << "Enter adjacency list: " << endl;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            int x;
            cin >> x;
            if(x==1) {
                adj[i].push_back(j);
            }
        }
    }

    if(checkBipartite(adj,n)) {
        cout<<"Yes Bipartite";
    }
    else {
        cout<<"Not Bipartite";
    }
}