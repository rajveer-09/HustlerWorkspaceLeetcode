class Solution {
    int dp[][];
    private int solve(int[][] matrix, int i, int j) {
        int n = matrix.length;
        
        if (i >= n) return 0;

        if(dp[i][j] != Integer.MIN_VALUE) return dp[i][j];

        int op1 = solve(matrix, i + 1, j);
        int op2 = Integer.MAX_VALUE;
        int op3 = Integer.MAX_VALUE;

        if (j - 1 >= 0) op2 = solve(matrix, i + 1, j - 1);
        if (j + 1 <= n - 1) op3 = solve(matrix, i + 1, j + 1);

        return dp[i][j] = matrix[i][j] + Math.min(Math.min(op1, op2), op3);
    }

    public int minFallingPathSum(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;

        dp = new int[n][m];
        
        for (int[] row : dp) {
            Arrays.fill(row, Integer.MIN_VALUE);
        }

        int minSum = Integer.MAX_VALUE;

        for (int j = 0; j < n; j++) {
            minSum = Math.min(minSum, solve(matrix, 0, j));
        }

        return minSum;
    }
}