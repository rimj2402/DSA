#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
void dfs(int r,int c,vector<vector<int>>& vis,vector<vector<char>>& board,int dirrow[],int dircol[]){
    vis[r][c]=1;
    for(int i=0;i<4;i++){
        int nrow=r+dirrow[i];
        int ncol=c+dircol[i];
        if(nrow>=0 && nrow<board.size() && ncol>=0 && ncol<board[0].size() && vis[nrow][ncol]==0 && board[nrow][ncol]=='O'){
            dfs(nrow,ncol,vis,board,dirrow,dircol);
        }
    }
}

    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int dirrow[]={-1,0,1,0};
        int dircol[]={0,1,0,-1};
        for(int j=0;j<n;j++){
            if(board[0][j]=='O' && vis[0][j]==0){
                dfs(0,j,vis,board,dirrow,dircol);
            }
            if(board[m-1][j]=='O' && vis[m-1][j]==0){
                dfs(m-1,j,vis,board,dirrow,dircol);
            }
        }
        for(int i=0;i<m;i++){
            if(board[i][0]=='O' && vis[i][0]==0){
                dfs(i,0,vis,board,dirrow,dircol);
            }
            if(board[i][n-1]=='O' && vis[i][n-1]==0){
                dfs(i,n-1,vis,board,dirrow,dircol);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};

int main(){
    vector<vector<char>> board={{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    Solution obj;
    obj.solve(board);
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}