#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m=mat.size(), n=mat[0].size(), oo=0x3f3f3f3f;
    vector<vector<int>> dis(m,vector<int>(n,oo));
    int dr[]={1,0,-1,0};
    int dc[]={0,1,0,-1};
    queue<pair<int,int>> q;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
        if(mat[i][j]==0){
            q.push({i,j});
            dis[i][j]=0;
        }
    }
    }
    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int nr=r+dr[k];
            int nc=c+dc[k];
            if(nr>=0&&nr<m&&nc>=0&&nc<n&&mat[nr][nc]!=0&&dis[nr][nc]==oo){
                dis[nr][nc]=dis[r][c]+1;
                q.push({nr,nc});
            }
            }
    }
    return dis;
}
int main()
{
    vector<vector<int>> mat={{0,0,0},{0,1,0},{1,1,3}};
    vector<vector<int>> res;
    res=updateMatrix(mat);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[0].size();j++){
        cout<<res[i][j]<<" ";
    }
    cout<<"\n";
    }
    
}