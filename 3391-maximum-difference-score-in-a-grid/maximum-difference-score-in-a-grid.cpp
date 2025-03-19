class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int maxScore = INT_MIN;
        vector<vector<int>> dp(n, vector<int>(m, 0));

        dp[0][0] = grid[0][0];

        for (int j = 1; j < m; j++) {
            dp[0][j] = min(dp[0][j - 1], grid[0][j]);
            maxScore = max(maxScore, grid[0][j] - dp[0][j - 1]);
        }

        for (int i = 1; i < n; i++) {
            dp[i][0] = min(dp[i - 1][0], grid[i][0]);
            maxScore = max(maxScore, grid[i][0] - dp[i - 1][0]);
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                int minPrev = min(dp[i - 1][j], dp[i][j - 1]);
                dp[i][j] = min(minPrev, grid[i][j]);
                maxScore = max(maxScore, grid[i][j] - minPrev);
            }
        }

        return maxScore;
    }
};