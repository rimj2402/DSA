#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool iscycle(int i,int vis[],int dfsvis[],vector<vector<int>>& adj){
            vis[i]=1;
            dfsvis[i]=1;
            for(auto it:adj[i]){
                if(!vis[it]){
                    if(iscycle(it,vis,dfsvis,adj)) return true;
                }
                else if(dfsvis[it]){
                    return true;
                }
            }
            dfsvis[i]=0;
            return false;
        }
     bool iscyclic(int V, vector<vector<int>>& adj){
        int vis[V]={0};
        int dfsvis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(iscycle(i,vis,dfsvis,adj)) return true;
            }
        }
        return false;
     }
};

int main(){
    int V=5;
    vector<vector<int>>adj(V);
    // Add edges to the adjacency list
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(1); // This creates a cycle

    Solution sol;
    if(sol.iscyclic(V, adj)){
        cout << "Cycle is present in the graph" << endl;
    }
    else{
        cout << "No cycle is present in the graph" << endl;
    }

    return 0;
}