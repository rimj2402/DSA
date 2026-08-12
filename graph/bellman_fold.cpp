#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>dist(V,1e8);
        dist[src]=0;
        for(int i=0;i<V-1;i++){
            for(auto it : edges){
                if(dist[it[0]] !=1e8 && dist[it[0]] + it[2] < dist[it[1]]){
                    dist[it[1]]=dist[it[0]] + it[2];
                }
            }
        }
        for(auto it :edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if(dist[u] + wt < dist[v]) return {-1};
        }
        return dist;
    }
};

int main(){
    int V;
    cin>>V;
    int E;
    cin>>E;
    vector<vector<int>> edges(E,vector<int>(3));
    for(int i=0;i<E;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges[i]={u,v,wt};
    }
    int src;
    cin>>src;
    Solution obj;
    vector<int> ans=obj.bellmanFord(V,edges,src);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}