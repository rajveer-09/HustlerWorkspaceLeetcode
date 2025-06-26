class Solution {
public:
    int dp[3000][3000];
    int solve(vector<int>& nums, int idx, int pre){
        if(idx >= nums.size()) return 0;

        if(dp[idx][pre + 1] != -1) return dp[idx][pre + 1];

        int take = 0, notTake = 0;

        if(pre == -1 || nums[idx] > nums[pre]){
            take = 1 + solve(nums, idx + 1, idx);
        }

        notTake = solve(nums, idx + 1, pre);

        return dp[idx][pre + 1] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));

        return solve(nums, 0, -1);
    }
};