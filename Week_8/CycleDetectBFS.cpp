#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;
bool sub(int src,vector<bool> vis,vector<int> adj[]){
    vis[src]=true;
    queue<pair<int,int>> q;
    q.push({src,-1});
    while(!q.empty()){
        int u=q.front().first;
        int p=q.front().second;
        q.pop();
        for(int v:adj[u]){
            if(!vis[v]){
                vis[v]=true;
                q.push({v,u});
            }
            else if(vis[v]&&v!=p){
                return true;
            }
        }
    }
    return false;
}
bool detectCycle(int V, vector<int> adj[]) {
    vector<bool> vis(V,false);
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(sub(i,vis,adj)){
                return true;
            }
        }
    }
    return false;
}


int main()
{
    
}