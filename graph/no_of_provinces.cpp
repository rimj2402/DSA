#include<bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<int>& visited,int i ,vector<vector<int>>& adjlst){
        visited[i]=1;
        for(auto it:adjlst[i]){
            if(!visited[it]) dfs(visited,it,adjlst);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>visited(n,0);
        int count=0;
        vector<vector<int>>adjlst(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjlst[i].push_back(j);
                    adjlst[j].push_back(i);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(visited,i,adjlst);
            }
        }
       return count;
    }
};

int main() {
    // Create a sample adjacency matrix
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    // Create solution object
    Solution sol;

    // Print the number of provinces
    cout << "Number of Provinces: " 
         << sol.findCircleNum(isConnected) << endl;

    return 0;
}