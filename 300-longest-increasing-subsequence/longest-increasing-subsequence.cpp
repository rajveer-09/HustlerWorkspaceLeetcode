class Solution {
public:
    int memo(vector<int>& nums, int idx, int prev, vector<vector<int>> &dp) {
        if (idx < 0) return 0;

        if (dp[idx][prev + 1] != -1) return dp[idx][prev + 1];

        int inc = 0;
        if (prev == -1 || nums[prev] > nums[idx]) {
            inc = 1 + memo(nums, idx - 1, idx, dp);
        }

        int exc = memo(nums, idx - 1, prev, dp);

        return dp[idx][prev + 1] = max(inc, exc);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return memo(nums, n - 1, -1, dp);
    }
};
