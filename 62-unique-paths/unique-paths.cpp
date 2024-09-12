class Solution {
public:
    int memo(int m, int n, int x, int y, vector<vector<int>>& dp) {
        if (x == m - 1 || y == n - 1) {
            return 1;
        }

        if (dp[x][y] != -1) return dp[x][y];

        int down = memo(m, n, x + 1, y, dp);
        int right = memo(m, n, x, y + 1, dp);

        return dp[x][y] = down + right;
    }

    int uniquePaths(int m, int n) {
        ios_base::sync_with_stdio(false);
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return memo(m, n, 0, 0, dp);
    }
};
