class Solution {
public:
    int fun(int n, vector<int>& dp) {
        if (n <= 1) return 1; // Base case

        if (dp[n] != -1) return dp[n]; // Return the result if already computed

        // Take the step: climb one step
        int takeOneStep = fun(n - 1, dp);

        // Take the step: climb two steps
        int takeTwoSteps = (n >= 2) ? fun(n - 2, dp) : 0;

        // Store the result in dp[n]
        dp[n] = takeOneStep + takeTwoSteps;

        return dp[n];
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1); // Initialize dp array with -1 (uncomputed)

        return fun(n, dp); // Compute the result using memoization
    }
};
