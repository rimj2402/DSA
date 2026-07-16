#include<bits/stdc++.h>
using namespace std;

class Solution
{
private:
    
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,st);
            }
        }
        st.push(node);
    }
    vector<int> topologicalSort(int V, vector<vector<int>> &adj)
    {
        stack<int>st;
        vector<int>vis(V,0);
        vector<int>result;
        for(int i=0;i<V;i++){
            if(!vis[i]) dfs(i,adj,vis,st);
        }
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};

int main(){
    int V=6;
    vector<vector<int>> adj(V);
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);
    
    Solution obj;
    vector<int> result=obj.topologicalSort(V,adj);
    for(auto it:result){
        cout<<it<<" ";
    }
}