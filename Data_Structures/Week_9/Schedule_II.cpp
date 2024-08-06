#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> adj[numCourses];
    for(int i=0;i<prerequisites.size();i++){
        int to=prerequisites[i][0],from=prerequisites[i][1];
        adj[from].push_back(to);
    }
    vector<int> degree(numCourses,0);
	vector<int> ans;
    queue<int> q;
    for(int i=0;i<numCourses;i++){
        for(auto it:adj[i]){
            degree[it]++;
        }
    }
    for(int i=0;i<numCourses;i++) if(degree[i]==0) q.push(i);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        ans.push_back(u);
        for(auto v:adj[u]){
            if(--degree[v]==0)
                q.push(v);
        }
    }
    if(ans.size()!=numCourses){
        return {};
    }
    else{
        return ans;
    }
        
}
int main()
{
    vector<vector<int>> ps={{1,2,3,4},{1,2},{3,4},{0,4},{}};
    vector<int> res=findOrder(5,ps);
    for(auto it:res){
        cout<<it<<" ";
    }

    return 0;
}