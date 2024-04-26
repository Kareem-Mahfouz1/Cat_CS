#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void DFS(int i,int j,vector<vector<bool>>& vis,vector<vector<int>>& grid){
    int drow[4]={0,-1,0,1};
    int dcol[4]={1,0,-1,0};
    int n=grid.size(),m=grid[0].size();
    vis[i][j]=true;
    for(int s=0;s<4;s++){
        int row=i+drow[s];
        int col=j+dcol[s];
        if(row>=0&&row<n&&col>=0&&col<m&&!vis[row][col]&&grid[row][col]==1){
            DFS(row,col,vis,grid);
        }
    }
}
int numEnclaves(vector<vector<int>>& grid) {
    int n=grid.size(),m=grid[0].size();
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    for(int i=0;i<m;i++){
        if(!vis[0][i]&&grid[0][i]==1)
            DFS(0,i,vis,grid);
        if(!vis[n-1][i]&&grid[n-1][i]==1)
            DFS(n-1,i,vis,grid);
    }
    for(int i=0;i<n;i++){
        if(!vis[i][0]&&grid[i][0]==1)
            DFS(i,0,vis,grid);
        if(!vis[i][m-1]&&grid[i][m-1]==1)
            DFS(i,m-1,vis,grid);
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
        if(grid[i][j]==1&&vis[i][j])
            grid[i][j]=0;
    }
    }
    int num=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
        if(grid[i][j]==1)
            num++;
    }
    }
    return num;
}

int main()
{
    
    
    return 0;
}