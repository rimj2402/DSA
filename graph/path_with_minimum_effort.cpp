#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
        > pq;

        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=0;

        pq.push({0,{0,0}});
        int dr[]={1,0,-1,0};
        int dc[]={0,1,0,-1};

        while(!pq.empty()){
            int diff=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(diff > dist[row][col]) continue;
            if(row==n-1 && col==m-1) return diff;
            for(int i=0;i<4;i++){
                int nr= row+ dr[i];
                int nc= col+ dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m) {
                    int newEffort = max(abs(heights[row][col]- heights[nr][nc]),diff);
                    if(newEffort < dist[nr][nc]) {
                        dist[nr][nc]=newEffort;
                        pq.push({newEffort,{nr,nc}});
                    }
                }
            }

        }
        return 0;
    }
};

int main() {
    vector<vector<int>> heights = {{1,2,2},{3,8,2},{5,3,5}};
    Solution obj;
    int ans = obj.minimumEffortPath(heights);
    cout << ans;
}