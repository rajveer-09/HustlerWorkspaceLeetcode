class Solution {
public:
    int memo(vector<vector<int>>& matrix, int idx, int col, vector<vector<int>>& dp) {
        int n = matrix.size();

        if (idx >= n ) return 0;
        
        if (col < 0 || col >= n) return INT_MAX;

        if (idx == n - 1 ) return matrix[idx][col];

        if (dp[idx][col] != INT_MAX) return dp[idx][col];

        int btl = INT_MAX, btm = INT_MAX, btr = INT_MAX;

        if (col - 1 >= 0) {
            btl = matrix[idx][col] + memo(matrix, idx + 1, col - 1, dp);
        }
        
        btm = matrix[idx][col] + memo(matrix, idx + 1, col, dp);

        if (col + 1 < n) {
            btr = matrix[idx][col] + memo(matrix, idx + 1, col + 1, dp);
        }

        return dp[idx][col] = min(btm, min(btr, btl));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(false);
        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            ans = min(ans, memo(matrix, 0, i, dp));
        }
        return ans;
    }
};