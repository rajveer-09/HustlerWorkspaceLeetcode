class Solution {
public:    
    int solve(vector<int>& cookies, int mask, int k, vector<vector<int>>& dp) {
        if (dp[mask][k] > 0)
            return dp[mask][k];
        if (k == 1) {
            // last person gets the rest
            int unfairness = 0;
            for (int j = 0; j < cookies.size(); j++) {
                if (mask & (1 << j))
                    continue;
                unfairness += cookies[j];
            }
            dp[mask][k] = unfairness;
            return unfairness;
        }
        int ans = INT_MAX;
        for (int i = 0; i < (1 << cookies.size()); i++) {
            if (i & mask)
                continue;
            int unfairness = 0;
            for (int j = 0; j < cookies.size(); j++) {
                if (i & (1 << j)) {
                    unfairness += cookies[j];
                }
            }
            unfairness = max(unfairness, solve(cookies, mask | i, k - 1, dp));
            ans = min(ans, unfairness);
        }
        dp[mask][k] = ans;
        return ans;
    }

    int distributeCookies(vector<int>& cookies, int k) {
        int len = cookies.size();
        vector<vector<int>> dp(1024, vector<int>(10, -1));
        return solve(cookies, 0, k, dp);
    }
};