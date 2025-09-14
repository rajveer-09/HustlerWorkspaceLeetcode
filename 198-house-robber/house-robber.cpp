class Solution {
public:
    int memo(vector<int>& money, int idx, vector<int>& dp){
        int n = money.size();
        if(idx >= n) return 0;
        if(idx == n - 1) return money[n - 1];

        if(dp[idx] != -1) return dp[idx];

        int take  = money[idx] + memo(money, idx + 2, dp);
        int notTake = memo(money, idx + 1, dp);

        return dp[idx] = max(take, notTake);
    }
    int rob(vector<int>& money) {
        int n = money.size();
        vector<int> dp(n, -1);

        int ans = memo(money, 0, dp);

        return ans;
    }
};