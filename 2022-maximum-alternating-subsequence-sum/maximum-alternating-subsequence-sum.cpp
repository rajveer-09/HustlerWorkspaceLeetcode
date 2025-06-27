class Solution {
public:
    long long dp[100005][2];

    long long solve(vector<int>& nums, int idx, int sign) {
        if (idx >= nums.size()) return 0;

        int signIndex = (sign == 1) ? 1 : 0;
        if (dp[idx][signIndex] != -1) return dp[idx][signIndex];

        long long take = sign * nums[idx] + solve(nums, idx + 1, -sign);
        long long notTake = solve(nums, idx + 1, sign);

        return dp[idx][signIndex] = max(take, notTake);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, 1);
    }
};
