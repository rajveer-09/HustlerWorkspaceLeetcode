class Solution {
    public:

    int dp[71][71][71];

    int dfs(int row, int c1, int c2, vector<vector<int>>& grid, int m, int n) {
        if (c1 < 0 || c1 >= n || c2 < 0 || c2 >= n) return INT_MIN;

        if (row == m - 1){
            return grid[row][c1] + (c1 == c2 ? 0 : grid[row][c2]);
        }

        if (dp[row][c1][c2] != -1) return dp[row][c1][c2];

        int maxCherries = 0;

        for (int move1 = -1; move1 <= 1; move1++) {
            for (int move2 = -1; move2 <= 1; move2++) {
                int val = dfs(row + 1, c1 + move1, c2 + move2, grid, m, n);
                maxCherries = max(maxCherries, val);
            }
        }

        int cherries = grid[row][c1] + (c1 == c2 ? 0 : grid[row][c2]);

        return dp[row][c1][c2] = cherries + maxCherries;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        memset(dp, -1, sizeof(dp));

        return dfs(0, 0, n - 1, grid, m, n);
    }
};