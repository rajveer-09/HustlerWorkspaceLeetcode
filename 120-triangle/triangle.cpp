class Solution {
public:
    int func(int i, int j, vector<vector<int> > &triangle, vector<vector<int>> &dp) {
        int n = triangle.size();

        if (i == n - 1) return triangle[i][j]; 

        if(dp[i][j] != INT_MAX) return dp[i][j];

        int down = triangle[i][j] + func(i + 1, j, triangle, dp);

        int diagonal = triangle[i][j] + func(i + 1, j + 1, triangle, dp);

        return dp[i][j] = min(down, diagonal);
   }
    int minimumTotal(vector<vector<int>>& triangle) {
        ios_base::sync_with_stdio(false);
        int n = triangle.size();
        vector<vector<int> > dp(n, vector<int>(n, INT_MAX));
        return func(0, 0, triangle, dp);
    }
};