class Solution {
    private int memo(int[][] grid, int i, int j, int[][] dp) {
        int n = grid.length;
        int m = grid[0].length;

        if (i == n - 1 && j == m - 1) return grid[i][j];
        
        if (i >= n || j >= m) return Integer.MAX_VALUE;

        if (dp[i][j] != -1) return dp[i][j];

        long right = grid[i][j] +  (long) memo(grid, i, j + 1, dp);
        long down = grid[i][j] + (long) memo(grid, i + 1, j, dp);

        return dp[i][j] =  (int) Math.min(right, down);
    }

    public int minPathSum(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        int[][] dp = new int[n][m];
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }

        return memo(grid, 0, 0, dp);
    }
}