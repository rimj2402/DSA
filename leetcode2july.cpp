#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> directions={{1,0},{-1,0},{0,-1},{0,1}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> result(m,vector<int> (n,INT_MAX));
        // result[i][j] =min health to reach from [0][0] to [i][j]
        deque<pair<int,int>> dq;
        result[0][0]= grid[0][0];
        dq.push_front({0,0});
        while(!dq.empty()){
            pair<int,int> curr = dq.front();
            int r = curr.first;
            int c = curr.second;
            dq.pop_front();

            for(auto & dir : directions){
                int newr=r+dir[0];
                int newc=c+dir[1];
                if(newr<0 || newr>=m || newc<0 || newc>=n) continue; 
                if(result[r][c]+grid[newr][newc] < result[newr][newc]){
                    result[newr][newc]=result[r][c]+grid[newr][newc];
                    if(grid[newr][newc]==0) dq.push_front({newr,newc});
                    else dq.push_back({newr,newc});
                }
            }
        }
        int x=result[m-1][n-1];
        return health-x>=1;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> grid = {{0, 1, 0}, {1, 0, 1}, {0, 1, 0}};
    int health = 5;

    bool canWalkSafely = sol.findSafeWalk(grid, health);
    if (canWalkSafely) {
        cout << "You can walk safely through the grid." << endl;
    } else {
        cout << "You cannot walk safely through the grid." << endl;
    }

    return 0;
}