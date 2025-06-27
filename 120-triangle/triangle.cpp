class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: fill the last row as is
        for (int j = 0; j < triangle[n - 1].size(); ++j) {
            dp[n - 1][j] = triangle[n - 1][j];
        }

        // Build from bottom up
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }

        // Top element is the answer
        return dp[0][0];
    }
};


