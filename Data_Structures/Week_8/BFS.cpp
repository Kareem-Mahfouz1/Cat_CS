#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;
const int N= 1e5, M= 2e5+5, oo=0x3f3f3f3f;

vector<int> adj[N];
int dis[N];

void BFS(int src){
    memset(dis, oo, sizeof dis);
    dis[src]=0;
    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:adj[u]){
            if(dis[v] == oo){
                q.push(v);
                dis[v]=dis[u]+1;
            }
        }
    }
}

int main()
{
    int n,m,u,v;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    BFS(0);
    cout<<"\n";
    for(int i=0;i<n;i++){
        cout<<i<<" "<<dis[i]<<"\n";
    }   
    return 0;
}