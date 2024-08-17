class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0) {
                    int part = dp[i - coins[j]];
                    if (part != INT_MAX) {
                        dp[i] = min(dp[i], 1 + part);
                    }
                }
            }
        }

        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }
};
