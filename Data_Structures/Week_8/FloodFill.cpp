#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size(),n=image[0].size();
        int dr[]={1,0,-1,0};
        int dc[]={0,1,0,-1};
        queue<pair<int,int>> q;
        int initial=image[sr][sc];
        image[sr][sc]=color;
        q.push({sr,sc});
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];
                if(nr>=0&&nr<m&&nc>=0&&nc<n&&image[nr][nc]==initial&&image[nr][nc]!=color){
                    image[nr][nc]=color;
                    q.push({nr,nc});
                }
            }
        }
        return image;
    }

int main()
{

    
    return 0;
}