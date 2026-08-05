#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int shortestDis(vector<vector<int>>& grid ,pair<int,int> src,pair<int,int>dest){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dist[i][j]=INT_MAX;
            }
        }
        dist[src.first][src.second]=0;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src.first,src.second}});
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().second.first;
            int col=q.front().second.second;
            int d=q.front().first;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && d+1<dist[nrow][ncol]){
                    if(nrow==dest.first && ncol==dest.second){
                        return d+1;
                    }
                    dist[nrow][ncol]=d+1;
                    q.push({d+1,{nrow,ncol}});
                }
            }
        }
        return -1;
    }
};

int main(){
    int n=5,m=4;
    vector<vector<int>> grid={{1,1,1,1},{1,1,0,1},{1,1,1,1},{1,1,0,0},{1,0,0,1}};
    pair<int,int> src={0,1};
    pair<int,int> dest={2,2};
    Solution obj;
    int ans=obj.shortestDis(grid,src,dest);
    cout<<ans;
}