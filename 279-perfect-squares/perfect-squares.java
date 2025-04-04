class Solution {
    int[] dp;

    int solve(int n){
        if(n == 0) return 0;

        if(n < 0) return Integer.MAX_VALUE;

        if(dp[n] != -1) return dp[n];

        int op = Integer.MAX_VALUE;

        for(int i = 1; i * i <= n; i++){
            int tmp = solve(n - i * i);

            if(tmp != Integer.MAX_VALUE){
                op = Math.min(op, tmp + 1);
            }
        }

        return dp[n] = op;
    }
    public int numSquares(int n) {
        dp = new int[n + 1];
        
        for(int i = 0; i <= n; i++) dp[i] = -1;

        return solve(n);
    }
}