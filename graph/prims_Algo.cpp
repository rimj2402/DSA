# include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        >pq;
        vector<pair<int,int>> adj[V];
        for(auto e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        // {wt,node}
        pq.push({0,0});
        vector<int> vis(V,0);
        int sum=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            int wt=it.first;
            
            if(vis[node]==1) continue;
            vis[node]=1;
            sum+=wt;
            for(auto it:adj[node]){
                int edw=it.second;
                int adjnode=it.first;
                if(!vis[adjnode]) pq.push({edw,adjnode});
            }
        }
        return sum;
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
    Solution obj;
    int ans=obj.spanningTree(V,edges);
    cout<<ans;
}