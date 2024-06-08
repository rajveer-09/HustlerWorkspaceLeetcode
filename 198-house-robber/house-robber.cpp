class Solution {
public:
    int fun(vector<int>& nums, int ind, vector<int>& dp) {
        if (ind >= nums.size()) return 0;
        if (dp[ind] != -1) return dp[ind];

        int pick = nums[ind] + fun(nums, ind + 2, dp);
        int npick = fun(nums, ind + 1, dp);

        dp[ind] = max(pick, npick);

        return dp[ind];
    }

    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> dp(nums.size(), -1);
        return fun(nums, 0, dp);
    }
};
