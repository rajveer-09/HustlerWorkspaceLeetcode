class Solution {
public:
    int solve(vector<int>& nums, int mask, int countOfOp, vector<int>& dp) {
        int m = nums.size(), n = nums.size() / 2;
        if (countOfOp >= n) {
            return 0;
        }
        if (dp[mask] != -1) {
            return dp[mask];
        }
        int maxScore = 0;
        for (int i = 0; i < m; ++i) {
            if (((mask >> i) & 1) == 1) {
                continue;
            }
            for (int j = i + 1; j < m; ++j) {
                if (((mask >> j) & 1) == 1) {
                    continue;
                }
                int newMask = mask | (1 << i) | (1 << j);
                int currScore = (countOfOp + 1) * gcd(nums[i], nums[j]);
                int remainingScore = solve(nums, newMask, countOfOp + 1, dp);
                maxScore = max(maxScore, currScore + remainingScore);
            }
        }
        return dp[mask] = maxScore;
    }

    int maxScore(vector<int>& nums) {
        int m = nums.size();
        int maxMaskValue = 1 << m; // 2^m
        vector<int> dp(maxMaskValue, -1);
        return solve(nums, 0, 0, dp);
    }
};