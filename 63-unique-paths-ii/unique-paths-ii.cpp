class Solution {
private:
    int func(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> &dp) {
        // If the current cell has an obstacle, return 0
        if (i >= 0 && j >= 0 && matrix[i][j] == 1) return 0;

        // If we're out of bounds, return 0
        if (i < 0 || j < 0) return 0;

        // Base case: if we're at the start, and there's no obstacle, return 1
        if (i == 0 && j == 0) return 1;

        // If the result is already computed, return it
        if (dp[i][j] != -1) return dp[i][j];

        // Calculate the number of ways by moving up and left recursively
        int up = func(i - 1, j, matrix, dp);
        int left = func(i, j - 1, matrix, dp);

        // Return and store the total number of ways in the DP table
        return dp[i][j] = up + left;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // If the start or the end is an obstacle, return 0
        if (matrix[0][0] == 1 || matrix[m-1][n-1] == 1) return 0;

        // Initialize DP table to memoize results
        vector<vector<int>> dp(m, vector<int>(n, -1)); 
        
        // Return the total number of paths
        return func(m-1, n-1, matrix, dp);
    }
};