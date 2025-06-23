class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int helper(int idx, bool canBuy, vector<int>& prices) {
        if (idx == n) return 0;
        if (dp[idx][canBuy] != -1) return dp[idx][canBuy];

        if (canBuy) {
            int buy = -prices[idx] + helper(idx + 1, false, prices);
            int skip = helper(idx + 1, true, prices);
            return dp[idx][canBuy] = max(buy, skip);
        } 
        else {
            int sell = prices[idx]; // sell once and done
            int skip = helper(idx + 1, false, prices);
            return dp[idx][canBuy] = max(sell, skip);
        }
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.assign(n, vector<int>(2, -1));
        return helper(0, true, prices);
    }
};
