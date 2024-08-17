#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
class Solution
{
private:
    int r[4] = {1, 0, 0, -1};
    int c[4] = {0, 1, -1, 0};
    void dfs(vector<vector<char>> &grid, int i, int j, vector<vector<bool>> &vis)
    {
        vis[i][j] = true;
        for (int idx = 0; idx < 4; idx++)
        {
            int nr = i + r[idx];
            int nc = j + c[idx];
            if (nr > -1 && nr < grid.size() && nc > -1 && nc < grid[0].size() && !vis[nr][nc] && grid[nr][nc] == '1')
                dfs(grid, nr, nc, vis);
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        int ctr = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    ctr++;
                    dfs(grid, i, j, vis);
                }
            }
        }
        return ctr;
    }
};