class Solution {
    int[][] dp;

    private int solve(int[][] grid, int i, int j) {
        int n = grid.length;
        int m = grid[0].length;

        if (i >= n || j >= m) {
            return 0;
        }

        if(grid[i][j] == 1) return 0;

        if (i == n - 1 && j == m - 1) {
            return 1;
        }
        

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        dp[i][j] = solve(grid, i + 1, j) + solve(grid, i, j + 1);

        return dp[i][j];
    }

    public int uniquePathsWithObstacles(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        dp = new int[n][m];

        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }

        return solve(grid, 0, 0);
    }
}