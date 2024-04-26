#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

void DFS(int u,vector<bool> &vis,vector<int> adj[],stack<int>& st) {
    vis[u]=true;
    for(int v:adj[u]){
        if(!vis[v]) DFS(v,vis,adj,st);
    }
    st.push(u);
}
vector<int> topoSort(int V, vector<int> adj[]) {
	vector<bool> vis(V,false);
    vector<int> ans;
    stack<int> st;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            DFS(i,vis,adj,st);
        }
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
int main()
{
    

    return 0;
}