#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>


using namespace std;
bool DFS(int u,vector<int> &vis,vector<int> &path,vector<vector<int>>& graph){
    vis[u]=1;
    path[u]=1;
    for(auto v:graph[u]){
        if(!vis[v]){
            if(DFS(v,vis,path,graph)) return true;
        }
        else if(path[v]==1){
            return true;
        }
    }
    path[u]=0;
    return false;
}
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int num=graph.size();
    vector<int> vis(num,0);
    vector<int> path(num,0);
    for(int i=0;i<num;i++){
        if(!vis[i]){
            DFS(i,vis,path,graph);
        }
    }
    vector<int> ans;
    for(int i=0;i<num;i++){
        if(path[i]==0)
            ans.push_back(i);
    }
    return ans;
}
int main()
{
    
    return 0;
}