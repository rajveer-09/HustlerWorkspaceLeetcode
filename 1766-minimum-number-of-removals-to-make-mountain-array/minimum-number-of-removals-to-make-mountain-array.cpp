class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n, 1), dp2(n, 1);

        // Longest Increasing Subsequence from the left
        for (int i = 1; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (nums[i] > nums[prev]) {
                    dp1[i] = max(dp1[i], dp1[prev] + 1);
                }
            }
        }

        // Longest Decreasing Subsequence from the right
        for (int i = n - 2; i >= 0; i--) {
            for (int prev = i + 1; prev < n; prev++) {
                if (nums[i] > nums[prev]) {
                    dp2[i] = max(dp2[i], dp2[prev] + 1);
                }
            }
        }

        int mini = INT_MAX;
        for (int i = 1; i < n - 1; i++) {
            if (dp1[i] > 1 && dp2[i] > 1) {
                mini = min(mini, n - (dp1[i] + dp2[i] - 1));
            }
        }
        return mini;
    }
};