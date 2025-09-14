class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // vector<vector<int>> dp(n, vector<int>(m, -1));

        // dp[0][0] = grid[0][0];

        // for(int i = 1; i < n; i++){
        //     dp[i][0] = dp[i - 1][0] + grid[i][0];
        // }

        // for(int j = 1; j < m; j++){
        //     dp[0][j] = dp[0][j - 1] + grid[0][j];
        // }

        // for(int i = 1; i < n; i++){
        //     for(int j = 1; j < m; j++){
        //         int right = dp[i][j - 1] + grid[i][j];
        //         int down = dp[i - 1][j] + grid[i][j];

        //         dp[i][j] = min(right, down);
        //     }
        // }
        // return dp[n - 1][m - 1];

        vector<int> dp(m + 1, INT_MAX);
        dp[m - 1] = grid[n - 1][m -1];

        for(int i = m - 2; i >= 0; i--){
            dp[i] = dp[i + 1] + grid[n - 1][i];
        }
        // dp[m - 1] = 0;

        for (int i = n - 2; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                dp[j] = grid[i][j] + min(dp[j], dp[j + 1]);
            }
        }

        return dp[0];
    }
};