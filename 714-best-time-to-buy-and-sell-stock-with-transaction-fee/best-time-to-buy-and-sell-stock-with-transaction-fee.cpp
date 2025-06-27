class Solution {
public:
    int dp[100001][2];

    int func(int ind, int buy, int fee, int n, vector<int>& arr) {
        if (ind == n) return 0;

        if (dp[ind][buy] != -1) return dp[ind][buy];

        int profit = 0;

        if (buy == 0) { // Can Buy
            profit = max(func(ind + 1, 0, fee, n, arr), 
                         -arr[ind] + func(ind + 1, 1, fee, n, arr));
        } else { // Can Sell
            profit = max(func(ind + 1, 1, fee, n, arr), 
                         arr[ind] - fee + func(ind + 1, 0, fee, n, arr));
        }

        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& arr, int fee) {
        int n = arr.size();
        memset(dp, -1, sizeof(dp));
        return func(0, 0, fee, n, arr);
    }
};
