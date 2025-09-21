class Solution {
public:
    int solve(vector<int>& jd, int idx, int d, vector<vector<int>>& dp) {
        if (d == 0 && idx >= jd.size()) {
            return 0;
        }
        if (d == 1) {
            int maxi = INT_MIN;
            for (int i = idx; i < jd.size(); i++) {
                maxi = max(maxi, jd[i]);
            }
            return maxi;
        }

        if (dp[idx][d] != -1) return dp[idx][d];

        int maxi = INT_MIN;
        int ans = INT_MAX;
        for (int i = idx; i <= jd.size() - d; i++) {
            maxi = max(maxi, jd[i]);
            ans = min(ans, maxi + solve(jd, i + 1, d - 1, dp));
        }

        return dp[idx][d] = ans;
    }

    int minDifficulty(vector<int>& jd, int d) {
        int n = jd.size();
        if (d > n) return -1;
        
        vector<vector<int>> dp(n, vector<int>(d + 1, -1));

        return solve(jd, 0, d, dp);
    }
};