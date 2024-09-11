class Solution {
public:
    int fun(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0)
            return 0;

        if (amount < 0)
            return INT_MAX; 

        if (dp[amount] != -1)
            return dp[amount];

        int ans = INT_MAX;

        for (int i = 0; i < coins.size(); i++) {
            int part = fun(coins, amount - coins[i], dp);
            if (part != INT_MAX) {
                ans = min(ans, 1 + part);
            }
        }
        
        dp[amount] = ans;
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);

        int ans = fun(coins, amount, dp);

        return (ans == INT_MAX) ? -1 : ans;
    }
};
