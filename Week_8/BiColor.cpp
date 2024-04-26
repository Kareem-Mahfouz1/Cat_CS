#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;
const int N= 1e5, M= 2e5+5;
const int RED=0, BLUE=1, NOT_COLORED=2;

vector<int> adj[N];
int color[N];
bool BiColor(int src){
    fill(color,color+N,NOT_COLORED);
    color[src]=RED;
    queue<int> q;
    q.push(src);
    
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v: adj[u]){

            if(color[v] == NOT_COLORED){
                color[v] = (color[u] == RED ? BLUE : RED);
                q.push(v);
            } else if(color[v]==color[u]){
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n,m,s,v;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>s>>v;
        adj[s].push_back(v);
        adj[v].push_back(s);
    }
    cout<<"\n";
    puts(BiColor(0) ? "yes" : "no");
    return 0;
}