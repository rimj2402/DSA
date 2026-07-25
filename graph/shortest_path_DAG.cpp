#include<bits/stdc++.h>
using namespace std;


class Solution {
    private:
    void toposort1(int node ,vector<pair<int,int>> adj[],int vis[],stack<int>&st){
        vis[node]=1;
        for(auto it : adj[node]){
            int v=it.first;
            if(!vis[v]){
                toposort1(v,adj,vis,st);
            }
        }
        st.push(node);
    }
    public:
    vector<int> shortest(int N, int M,vector<vector<int>>& edges){
        // graph 
        vector<pair<int,int>> adj[N];
        for(int i=0;i<M;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
        }

        // toposort
        int vis[N]={0};
        stack<int>st;
        for(int i=0;i<N;i++){
            if(!vis[i]){
                toposort1(i,adj,vis,st);
            }
        }

        // shortest path
        vector<int> dist(N,1e9);
        dist[0]=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            for(auto it : adj[node]){
                int v=it.first;
                int w=it.second;
                if(dist[node] != 1e9 && dist[node]+w<dist[v]){
                    dist[v]=dist[node]+w;
                }
            }
        }
        return dist;
    }
};

int main(){
    int N=6;
    int M=7;
    vector<vector<int>> edges={{0,1,2},{0,4,1},{1,2,3},{4,2,2},{4,5,4},{2,3,6},{5,3,1}};
    Solution obj;
    vector<int> ans=obj.shortest(N,M,edges);
    for(int i=0;i<N;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}