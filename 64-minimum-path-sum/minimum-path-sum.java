class Solution {
    long memo(int [][] grid, int i, int j, long[][] dp){
        int n = grid.length;
        int m = grid[0].length;

        if (i == n - 1 && j == m - 1) return grid[i][j];

        if(i >= n || j >= m) return Integer.MAX_VALUE;

        if(dp[i][j] != -1) return dp[i][j];

        long right = grid[i][j] + memo(grid, i, j + 1, dp);
        long down = grid[i][j] + memo(grid, i + 1, j, dp);

        return dp[i][j] = Math.min(right, down);
    }
    public int minPathSum(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        long [][] dp = new long[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = -1;
            }
        }

        return (int)memo(grid, 0, 0, dp);
    }
}