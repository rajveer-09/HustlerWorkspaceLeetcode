class Solution {
public:
    // define the rec fun
    // min sum
    int solve(vector<vector<int>>& triangle, int row, int col, vector<vector<int>>& dp){
        int n = triangle.size();
        if(row == n){
            return 0;
        }

        if(dp[row][col] != INT_MAX) return dp[row][col];

        int ans = INT_MAX;

        int down = solve(triangle, row + 1, col, dp);
        int diag = solve(triangle , row + 1, col + 1, dp);

        return dp[row][col] = triangle[row][col] + min(down, diag);
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n - 1].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

        return solve(triangle, 0, 0, dp);
    }
};