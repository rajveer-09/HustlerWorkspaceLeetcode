class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Base case: first row is same as grid
        for(int j = 0; j < m; j++) {
            dp[0][j] = grid[0][j];
        }

        // Fill dp table row by row
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int mini = INT_MAX;
                for(int k = 0; k < m; k++) {
                    if(k != j) {
                        mini = min(mini, dp[i-1][k]);
                    }
                }
                dp[i][j] = grid[i][j] + mini;
            }
        }

        // Answer is min in last row
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};
