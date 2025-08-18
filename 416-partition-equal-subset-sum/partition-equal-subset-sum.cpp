class Solution {
public:
    int dp[201][20001];

    bool solve(vector<int>& nums, int idx, int tsum, int sum) {
        int n = nums.size();
        if((tsum - sum) == sum) return true;

        if (idx >= n) {
            return false;
        }

        if (dp[idx][sum] != -1) return dp[idx][sum];

        bool take = solve(nums, idx + 1, tsum, sum + nums[idx]);
        bool not_take = solve(nums, idx + 1, tsum, sum);

        return dp[idx][sum] = (take || not_take);
    }

    bool canPartition(vector<int>& nums) {
        int tsum = accumulate(nums.begin(), nums.end(), 0);
        memset(dp, -1, sizeof(dp));

        return solve(nums, 0, tsum, 0);
    }
};
