class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 1) {
            return;
        }
        grid[i][j] = 1;
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Remove all '0's connected to borders
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 0) dfs(grid, i, 0);
            if (grid[i][m - 1] == 0) dfs(grid, i, m - 1);
        }
        
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 0) dfs(grid, 0, j);
            if (grid[n - 1][j] == 0) dfs(grid, n - 1, j);
        }

        int closedIslands = 0;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (grid[i][j] == 0) {
                    dfs(grid, i, j);
                    closedIslands++;
                }
            }
        }

        return closedIslands;
    }
};
