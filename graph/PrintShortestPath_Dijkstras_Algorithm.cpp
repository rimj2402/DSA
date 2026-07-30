#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> shortestpath(int N, int M, vector<vector<int>>& edges,int src){
        vector<pair<int,int>>adj[N+1];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        vector<int>dist(N,INT_MAX);
        dist[src]=0;
        vector<int>parent(N,-1);
        parent[src]=src;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,src});
        while(!pq.empty()){
            int node=pq.top().second;
            int dis=pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                int adjnode=it.first;
                int edgwt=it.second;
                if(dis+edgwt < dist[adjnode]){
                    dist[adjnode]= dis+edgwt;
                    parent[adjnode]=node;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        int node=N-1;
        vector<int>path;
        while(parent[node]!=node){
            path.insert(path.begin(),node);
            node=parent[node];
        }
        path.insert(path.begin(),src);
        return path;
    }
};

int main(){
    int N=6;
    int M=7;
    vector<vector<int>> edges={{0,1,2},{0,4,1},{1,2,3},{4,2,2},{4,5,4},{2,3,6},{5,3,1}};
    int src=0;
    Solution obj;
    vector<int> ans=obj.shortestpath(N,M,edges,src);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
