class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;  // Base case: one way to make zero sum (using no elements)

        for (int i = 1; i <= target; i++) {
            for (int num : nums) {
                if (num <= i) {
                    // Check for potential overflow before updating dp[i]
                    if (dp[i] > INT_MAX - dp[i - num]) {
                        // If overflow is detected, set dp[i] to a value that signifies an invalid state
                        dp[i] = INT_MAX;
                    } 
                    else {
                        dp[i] += dp[i - num];
                    }
                }
            }
        }

        return dp[target];
    }
};
