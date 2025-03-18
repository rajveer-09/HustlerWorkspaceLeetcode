class Solution {
public:
    int memo(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp){
        int n = matrix.size();
        int m = matrix[0].size();

        if(i < 0 || j < 0 || j >= m) return INT_MAX;

        if(i == 0) return matrix[i][j];

        if(dp[i][j] != INT_MAX) return dp[i][j];

        long long d = matrix[i][j] * 1LL + memo(matrix, i - 1, j, dp);
        long long rd = matrix[i][j] * 1LL + memo(matrix, i - 1, j - 1, dp);
        long long ld = matrix[i][j] * 1LL + memo(matrix, i - 1, j + 1, dp);

        return dp[i][j] = (int)min({d, rd, ld});
        
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

        int ans = INT_MAX;

        for(int j = 0; j < m; j++){
            ans = min(ans, memo(matrix, n - 1, j, dp)); 

        }

        return ans;
    }
};