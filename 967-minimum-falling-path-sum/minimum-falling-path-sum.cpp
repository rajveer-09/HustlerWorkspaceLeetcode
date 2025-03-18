class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int d = dp[i - 1][j];
                int ld = (j > 0) ? dp[i - 1][j - 1] : INT_MAX;
                int rd = (j < m - 1) ? dp[i - 1][j + 1] : INT_MAX;

                dp[i][j] = matrix[i][j] + min({d, ld, rd});
            }
        }

        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};