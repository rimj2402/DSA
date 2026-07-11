#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    bool detect(vector<int>&vis , vector<vector<int>>& adj , int src){
        vis[src]=1;
        queue<pair<int,int>>q;
        q.push({src,-1});
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto adjnode:adj[node]){
                if(!vis[adjnode]){
                    vis[adjnode]=1;
                    q.push({adjnode,node});
                }
                else if(parent!=adjnode){
                    return true;
                }
            }
        }
        return false;
    }
    public:
bool iscycle(int V, vector<vector<int>>& adj){
    vector<int>vis(V,0);
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(detect(vis,adj,i)) return true;
        }
    }
    return false;                           
}
};

int main(){
    int V=5;
    vector<vector<int>>adj(V);
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(3);

    Solution obj;
    if(obj.iscycle(V,adj)){
        cout<<"Cycle is present"<<endl;
    }
    else{
        cout<<"Cycle is not present"<<endl;
    }
}