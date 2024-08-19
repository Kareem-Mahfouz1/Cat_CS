#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &preq)
    {
        vector<int> adj[numCourses];
        queue<int> q;
        vector<int> completed;
        for (int i = 0; i < preq.size(); i++)
        {
            int to = preq[i][0];
            int from = preq[i][1];
            adj[from].push_back(to);
        }
        vector<int> degree(numCourses, 0);
        for (int i = 0; i < numCourses; i++)
        {
            for (auto it : adj[i])
                degree[it]++;
        }
        for (int i = 0; i < numCourses; i++)
            if (degree[i] == 0)
                q.push(i);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            completed.push_back(cur);
            for (auto neighbor : adj[cur])
                if (--degree[neighbor] == 0)
                    q.push(neighbor);
        }
        return completed.size() == numCourses;
    }
};