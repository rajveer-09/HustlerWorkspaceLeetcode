class Solution {
    int[][] dp;
    private int solve(List<List<Integer>> triangle, int row, int idx) {
        int n = triangle.size();

        if (row == n) return 0;

        if (dp[row][idx] != Integer.MAX_VALUE) return dp[row][idx];

        int curr = triangle.get(row).get(idx);

        int op1 = curr + solve(triangle, row + 1, idx);
        int op2 = curr + solve(triangle, row + 1, idx + 1);

        return dp[row][idx] = Math.min(op1, op2);
    }

    public int minimumTotal(List<List<Integer>> triangle) {

        int n = triangle.size();
        dp = new int[n][n]; 

        for (int[] row : dp) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }

        return solve(triangle, 0, 0);
    }
}