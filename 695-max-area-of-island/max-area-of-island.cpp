class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int currentArea = dfs(grid, visited, i, j);
                    maxArea = max(maxArea, currentArea);
                }
            }
        }

        return maxArea;
    }

private:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();

        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0 || visited[i][j]) {
            return 0;
        }

        visited[i][j] = true;
        int area = 1;

        // Perform DFS in all four possible directions
        area += dfs(grid, visited, i - 1, j); // up
        area += dfs(grid, visited, i + 1, j); // down
        area += dfs(grid, visited, i, j - 1); // left
        area += dfs(grid, visited, i, j + 1); // right

        return area;
    }
};