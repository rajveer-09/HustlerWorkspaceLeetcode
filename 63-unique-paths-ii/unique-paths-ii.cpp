class Solution {
public:
    int memo(vector<vector<int>>& matrix, int idx, int col, vector<vector<int>>& dp) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Base case: if we reach the bottom-right corner
        if (idx == n - 1 && col == m - 1) {
            return matrix[idx][col] == 1 ? 0 : 1;
        }

        // If out of bounds or on an obstacle
        if (idx >= n || col >= m || matrix[idx][col] == 1) {
            return 0;
        }

        if (dp[idx][col] != -1) {
            return dp[idx][col];
        }

        int right = memo(matrix, idx, col + 1, dp);
        int down = memo(matrix, idx + 1, col, dp);

        return dp[idx][col] = right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(false);
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return memo(matrix, 0, 0, dp);
    }
};
