class Solution {
public:
    int memo(vector<vector<int>>& matrix, int idx, int col, vector<vector<int>>& dp) {
        int n = matrix.size(), m = matrix[0].size();

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
        // ios_base::sync_with_stdio(false);
        int n = matrix.size(), m = matrix[0].size();

        // vector<vector<int>> dp(n, vector<int>(m, -1));

        // return memo(matrix, 0, 0, dp);

        vector<vector<int>> dp(n, vector<int>(m, 0));

        for(int j = 0; j < m; j++) {
            if(matrix[0][j] == 0) dp[0][j] = 1;
            else break;
        }
        for(int i = 0; i < n; i++) {
            if(matrix[i][0] == 0) dp[i][0] = 1;
            else break;
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[i][j] == 1){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};
