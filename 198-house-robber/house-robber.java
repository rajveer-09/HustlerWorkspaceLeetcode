class Solution {
    public int memo(int[] nums, int idx, int[] dp) {
        if (idx >= nums.length) return 0;

        if (dp[idx] != -1) return dp[idx];

        int take = nums[idx] + memo(nums, idx + 2, dp);
        int notTake = memo(nums, idx + 1, dp);

        return dp[idx] = Math.max(take, notTake);
    }

    public int rob(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];

        for (int i = 0; i < n; i++) dp[i] = -1;

        return memo(nums, 0, dp);
    }
}