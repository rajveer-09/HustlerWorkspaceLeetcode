class Solution {
public:
    // Recursive function to solve the problem
    int solve(vector<int>& nums, vector<bool>& used, int countOfOp, vector<vector<int>>& dp) {
        int n = nums.size() / 2;  // Number of operations to perform

        // Base case: if all operations are performed, return 0
        if (countOfOp >= n) {
            return 0;
        }

        // Create a unique key for the current state based on the used array
        int key = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) {
                key |= (1 << i);
            }
        }

        // Check if the result for the current state is already computed
        if (dp[countOfOp][key] != -1) {
            return dp[countOfOp][key];
        }

        int maxScore = 0;  // Variable to track the maximum score

        // Iterate over all pairs of elements in nums
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;  // Skip if the i-th element is already selected

            for (int j = i + 1; j < nums.size(); ++j) {
                if (used[j]) continue;  // Skip if the j-th element is already selected

                // Mark elements i and j as used
                used[i] = true;
                used[j] = true;

                // Calculate the score for the current pair
                int currScore = (countOfOp + 1) * gcd(nums[i], nums[j]);

                // Recursively calculate the remaining score
                int remainingScore = solve(nums, used, countOfOp + 1, dp);

                // Update the maximum score
                maxScore = max(maxScore, currScore + remainingScore);

                // Unmark elements i and j to backtrack
                used[i] = false;
                used[j] = false;
            }
        }

        // Cache the result for the current state and return it
        return dp[countOfOp][key] = maxScore;
    }

    // Main function to compute the maximum score
    int maxScore(vector<int>& nums) {
        int m = nums.size();  // Total number of elements in nums
        int n = nums.size() / 2;

        vector<bool> used(m, false);  // Array to track used elements
        vector<vector<int>> dp(n, vector<int>(1 << m, -1));  // DP table for memoization

        // Start the recursive function with 0 operations performed
        return solve(nums, used, 0, dp);
    }
};