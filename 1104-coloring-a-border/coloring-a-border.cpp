class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int originalColor = grid[row][col];
        vector<pair<int, int>> borderCells;
        
        dfs(grid, visited, borderCells, row, col, originalColor);
        
        for (auto& cell : borderCells) {
            grid[cell.first][cell.second] = color;
        }
        
        return grid;
    }

private:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, vector<pair<int, int>>& borderCells, int i, int j, int originalColor) {
        int n = grid.size();
        int m = grid[0].size();
        visited[i][j] = true;

        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        bool isBorder = false;

        for (int k = 0; k < 4; ++k) {
            int newRow = i + directions[k][0];
            int newCol = j + directions[k][1];

            if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= m || grid[newRow][newCol] != originalColor) {
                isBorder = true;
            } else if (!visited[newRow][newCol]) {
                dfs(grid, visited, borderCells, newRow, newCol, originalColor);
            }
        }

        if (isBorder) {
            borderCells.push_back({i, j});
        }
    }
};