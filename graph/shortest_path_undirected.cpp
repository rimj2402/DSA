#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges,int src) {
        vector<int>adj[N];
        for(int i=0;i<M;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>dist(N, INT_MAX);
        dist[src] = 0;
        queue<int>q;
        q.push(src);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : adj[u]){
                if(dist[u] + 1 < dist[v]){
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist;
    }
};

int main(){
    int N=6;
    int M=7;
    vector<vector<int>> edges={{0,1},{0,4},{1,2},{4,2},{4,5},{2,3},{5,3}};
    int src=0;
    Solution obj;
    vector<int> ans=obj.shortestPath(N,M,edges,src);
    for(int i=0;i<N;i++){
        if(ans[i]==INT_MAX){
            cout<<"-1 ";
        }
        else{
            cout<<ans[i]<<" ";
        }
    }
    return 0;
}