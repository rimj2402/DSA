#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void dfs(int node,vector<int>& lst, vector<vector<int>>& adj, vector<int>& visited) {
    visited[node]=1;
    lst.push_back(node);
    for(auto &ngh:adj[node]){
        if(visited[ngh]==0){
            dfs(ngh,lst,adj,visited);
        }
    }
}
vector<int> dfsOfGraph(int V, vector<vector<int>>& adj) {
    int n=adj.size();
    vector<int>lst;
    int start=0;
    vector<int>visited(n,0);
    // for all type of graphs
    for(int i = 0; i < V; i++) {
    if(!visited[i]) {
        dfs(i, lst, adj, visited);
    }
}
    return lst;
}
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution sol;
    vector<int> result = sol.dfsOfGraph(n, adj);
    for(auto &x: result){
        cout<<x<<" ";
    }
    return 0;
}