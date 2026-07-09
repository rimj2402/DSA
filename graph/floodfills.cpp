#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        
        int vis[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==sr&&j==sc) vis[i][j]=1;
                else vis[i][j]=0;
            }
        }
        
        queue<pair<int,int>>q;
        q.push({sr,sc});
        
        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};
        
        int starting_pixel=image[sr][sc];
        image[sr][sc]=color;
        
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+drow[i];
                int nc=c+dcol[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && image[nr][nc]==starting_pixel && vis[nr][nc]!=1){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                    image[nr][nc]=color;
                }
            }
        }
        return image;
    }
};

int main() {
    // Create a sample image
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    // Starting pixel coordinates and new color
    int sr = 1, sc = 1, color = 2;

    // Create solution object
    Solution sol;

    // Perform flood fill
    vector<vector<int>> result = sol.floodFill(image, sr, sc, color);

    // Print the modified image
    cout << "Modified Image after Flood Fill:" << endl;
    for (const auto& row : result) {
        for (const auto& pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}