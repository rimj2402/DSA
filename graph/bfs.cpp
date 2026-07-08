#include<bits/stdc++.h>
using namespace std;

void bfs(int start, vector<vector<int>>& adj, vector<int>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " "; // Print the node as it is visited
        for(auto &ngh : adj[node]) {
            if(visited[ngh] == 0) {
                visited[ngh] = 1;
                q.push(ngh);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m; // Number of vertices and edges

    // Create an adjacency list
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Vector to track visited nodes
    vector<int> visited(n, 0);

    // Perform BFS for each unvisited node
    for(int i = 0; i < n; i++) {
        if(visited[i] == 0) {
            cout << "BFS starting from node " << i << ": ";
            bfs(i, adj, visited);
            cout << endl;
        }
    }

    return 0;
}