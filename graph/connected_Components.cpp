#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges){
        // create an adjacency list
        vector<vector<int>> adj(n);
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        // vector to track visited nodes
        vector<int> visited(n,0);
        // variable to count connected components
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                // start bfs from this node
                queue<int>q;
                q.push(i);
                visited[i]=1;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(auto &ngh:adj[node]){
                        if(visited[ngh]==0){
                            visited[ngh]=1;
                            q.push(ngh);
                        }
                    }
                }
            }
        }
        return count;
    }
};

int main() {
    // Number of vertices
    int V = 5;

    // List of undirected edges
    vector<vector<int>> edges = {{0,1},{1,2},{3,4}};

    // Create solution object
    Solution sol;

    // Print the number of connected components
    cout << "Number of Connected Components: " 
         << sol.countComponents(V, edges) << endl;

    return 0;
}