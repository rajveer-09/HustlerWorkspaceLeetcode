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
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for(int j = 0; j < n; j++) dp[0][j] = 1;
        for(int i = 0; i < m; i++) dp[i][0] = 1;

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};
