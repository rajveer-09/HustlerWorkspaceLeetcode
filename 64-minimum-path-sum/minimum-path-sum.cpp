class Solution {
public:
    int memo(vector<vector<int>>& grid, int idx, int col, vector<vector<int>> &dp){
        int n = grid.size();
        int m = grid[0].size();

        if(idx == n-1 && col == m-1) return grid[idx][col];

        if(idx >= n || col >= m) return INT_MAX;

        if (dp[idx][col] != -1) {
            return dp[idx][col];
        }

        int down = memo(grid, idx + 1, col, dp);
        int right = memo(grid, idx, col + 1, dp);

        return dp[idx][col] = min(down, right) + grid[idx][col];
    }
    int minPathSum(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return memo(grid, 0, 0, dp);
    }
};