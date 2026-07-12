#include <bits/stdc++.h>
using namespace std;    

class Solution {
public:
void dfs(int r,int c,vector<vector<int>>& vis,vector<vector<int>>& grid,int dirrow[],int dircol[]){
    vis[r][c]=1;
    for(int i=0;i<4;i++){
        int nrow=r+dirrow[i];
        int ncol=c+dircol[i];
        if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
            dfs(nrow,ncol,vis,grid,dirrow,dircol);
        }
    }
}
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int dirrow[]={-1,0,1,0};
        int dircol[]={0,1,0,-1};
        int ans=0;
        for(int j=0;j<n;j++){
            if(grid[0][j]==1 && vis[0][j]==0){
                dfs(0,j,vis,grid,dirrow,dircol);
            }
            if(grid[m-1][j]==1 && vis[m-1][j]==0){
                dfs(m-1,j,vis,grid,dirrow,dircol);
            }
        }
        for(int i=0;i<m;i++){
            if(grid[i][0]==1 && vis[i][0]==0){
                dfs(i,0,vis,grid,dirrow,dircol);
            }
            if(grid[i][n-1]==1 && vis[i][n-1]==0){
                dfs(i,n-1,vis,grid,dirrow,dircol);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> grid={{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    Solution obj;
    int ans=obj.numEnclaves(grid);
    cout<<ans<<endl;
}