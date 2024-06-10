class Solution {
public:
  int fun(vector<int> const& coins, int target, vector<int>& dp) {
    // Base case: If target is 0, no coins needed
    if (target == 0) {
      return 0;
    }
    if(dp[target]!=-1) return dp[target];
    // Initialize minimum coins as infinity (worst case)
    int minCoins = INT_MAX;

    // Try using each coin denomination
    for (int i = 0; i < coins.size(); i++) {
      // Check if the coin is valid for the current target
      if (target - coins[i] >= 0) {
        // Recursively calculate minimum coins for the remaining target
        int subAns = fun(coins, target - coins[i], dp);

        // If a valid combination is found, update minimum coins
        if (subAns != INT_MAX) {
          minCoins = min(minCoins, 1 + subAns); // Add 1 for current coin
        }
      }
    }

    // Return minimum coins found (or INT_MAX if no valid combination)
    return dp[target] = minCoins;
  }

  int coinChange(vector<int>& coins, int amount) {
    // Initialize memoization array with -1
    vector<int> dp(amount + 1, -1);
    dp[0]=0;
    // Call recursive function and return result
    if(fun(coins, amount, dp) == INT_MAX) return -1;
    return fun(coins, amount, dp);
  }
};
