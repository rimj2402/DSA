#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int vis[m][n];
        // {{r,c},t}
        // int cntfresh=0;
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    vis[i][j]=2;
                    q.push({{i,j},0});
                }
                else vis[i][j]=0;
                // if(grid[i][j]==1) cntfresh++;
            }
        }
        int time=0;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        // int cnt=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            time=max(time,t);
            for(int i=0;i<4;i++){
                int nr=r+drow[i];
                int nc=c+dcol[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1 && vis[nr][nc]!=2){
                    q.push({{nr,nc},t+1});
                    vis[nr][nc]=2;
                    // cnt++;
                }
            }
        }
        // if(cnt!=cntfresh) return -1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]!=2 && grid[i][j]==1) return -1;
            }
        }
        return time;
    }
};

int main() {
    // Create a sample grid
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    // Create solution object
    Solution sol;

    // Calculate the time taken for all oranges to rot
    int result = sol.orangesRotting(grid);

    // Print the result
    if(result == -1) {
        cout << "Not all oranges can rot." << endl;
    } else {
        cout << "Time taken for all oranges to rot: " << result << endl;
    }

    return 0;
}