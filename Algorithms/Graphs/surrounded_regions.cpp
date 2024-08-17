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
            if (nr > -1 && nr < grid.size() && nc > -1 && nc < grid[0].size() && !vis[nr][nc] && grid[nr][nc] == 'O')
                dfs(grid, nr, nc, vis);
        }
    }

public:
    void solve(vector<vector<char>> &board)
    {
        int rows = board.size(), cols = board[0].size();
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; i++) // columns check
        {
            if (board[i][0] == 'O' && !vis[i][0])
                dfs(board, i, 0, vis);
            if (board[i][cols - 1] == 'O' && !vis[i][cols - 1])
                dfs(board, i, cols - 1, vis);
        }
        for (int i = 0; i < cols; i++) // rows check
        {
            if (board[0][i] == 'O' && !vis[0][i])
                dfs(board, 0, i, vis);
            if (board[rows - 1][i] == 'O' && !vis[rows - 1][i])
                dfs(board, rows - 1, i, vis);
        }
        for (int i = 0; i < rows; i++) // flipping
        {
            for (int j = 0; j < cols; j++)
            {
                if (board[i][j] == 'O' && !vis[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};