#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;
int orangesRotting(vector<vector<int>>& grid) {
    int m=grid.size(),n=grid[0].size();
    vector<vector<int>> vis(m,vector(n,-1));
    int tm=0;
    int dR[]={1,0,-1,0};
    int dC[]={0,1,0,-1};
    
    queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
            if(grid[i][j]==2){
                q.push({i,j});
                vis[i][j]=0;
            }
         }
        }
        while(!q.empty()){
            int oR=q.front().first;
            int oC=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nR=oR+dR[k];
                int nC=oC+dC[k];
                if(nR>=0&&nR<m&&nC>=0&&nC<n&& grid[nR][nC]==1){
                    grid[nR][nC]=2;
                    tm=vis[oR][oC]+1;
                    vis[nR][nC]=tm;
                    q.push({nR,nC});
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                return -1;
            }
         }
        }
        return tm;
    }

int main()
{
    vector<vector<int>> grid={{2,1,1},
                              {1,1,0},
                              {0,1,1}
                              };
    cout<<orangesRotting(grid);
    return 0;
}