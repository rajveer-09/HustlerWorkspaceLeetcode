class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Initialize dp vector with size amount + 1 and fill with infinity
        vector<int> dp(amount + 1, numeric_limits<int>::max());
        
        // Base case: 0 coins needed to make 0 amount
        dp[0] = 0;
        
        // Iterate through each coin
        for (int coin : coins) {
            // Update dp values for each amount from coin to amount
            for (int i = coin; i <= amount; ++i) {
                if (dp[i - coin] != numeric_limits<int>::max()) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        // If dp[amount] is still infinity, it means it's impossible to make the amount
        return dp[amount] == numeric_limits<int>::max() ? -1 : dp[amount];
    }
};