class Solution {
    public:

    int dp[71][71][71];

    int dfs(int row, int c1, int c2, vector<vector<int>>& grid, int m, int n) {
        if (c1 < 0 || c1 >= n || c2 < 0 || c2 >= n) return INT_MIN;

         // Base case: Last row reached
        if (row == m - 1) {
            if (c1 == c2) return grid[row][c1];            // both robots on same cell, count once
            else return grid[row][c1] + grid[row][c2];     // different cells, count both
        }

        if (dp[row][c1][c2] != -1) return dp[row][c1][c2];

        int maxCherries = 0;
        // Try all 9 combinations of moves (left, stay, right for both robots)
        for (int move1 = -1; move1 <= 1; move1++) {
            for (int move2 = -1; move2 <= 1; move2++) {
                int val = dfs(row + 1, c1 + move1, c2 + move2, grid, m, n);
                maxCherries = max(maxCherries, val);
            }
        }
        // Pick current cherries from (row, c1) and (row, c2)
        int cherries = grid[row][c1];
        if (c1 != c2) cherries += grid[row][c2]; // avoid double count

        return dp[row][c1][c2] = cherries + maxCherries;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        memset(dp, -1, sizeof(dp));

        return dfs(0, 0, n - 1, grid, m, n);
    }
};
