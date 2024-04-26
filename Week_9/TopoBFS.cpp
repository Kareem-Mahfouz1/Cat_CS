#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

vector<int> topoSort(int V, vector<int> adj[]) {
	vector<int> degree(V,0);
	vector<int> ans;
    queue<int> q;
    for(int i=0;i<V;i++){
        for(auto it:adj[i]){
            degree[it]++;
        }
    }
    for(int i=0;i<V;i++) if(degree[i]==0) q.push(i);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        ans.push_back(u);
        for(auto v:adj[u]){
            if(--degree[v]==0)
                q.push(v);
        }
    }
    return ans;
}
int main()
{
    

    return 0;
}