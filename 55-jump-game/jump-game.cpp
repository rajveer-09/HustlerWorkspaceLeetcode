class Solution {
public:
    // bool memo(vector<int>& nums, int idx, vector<int>& dp) {
    //     if (idx >= nums.size() - 1) return true;

    //     if (dp[idx] != -1) return dp[idx];
        
    //     // Start from 1 to avoid infinite recursion
    //     for (int j = 1; j <= nums[idx]; j++) { 
    //         if (memo(nums, idx + j, dp)) {
    //             return dp[idx] = true;
    //         }
    //     }
        
    //     return dp[idx] = false;
    // }

    // bool canJump(vector<int>& nums) {
    //     vector<int> dp(nums.size(), -1);
    //     return memo(nums, 0, dp);
    // }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;

        for (int i = 0; i < n; ++i) {
            if (i > farthest) {
                return false;
            }
            farthest = max(farthest, i + nums[i]);

            if (farthest >= n - 1) {
                return true;
            }
        }

        return true;
    }
};
