class Solution {
public:
    int memo(vector<int>& jD, int n, int idx, int d, vector<vector<int>>& dp) {
        if (d == 1) {
            int maxi = jD[idx];
            for (int i = idx; i < n; i++) {
                maxi = max(maxi, jD[i]);
            }
            return maxi;
        }

        if (dp[idx][d] != -1) return dp[idx][d];

        int maxi = jD[idx];
        int ans = INT_MAX;

        for (int i = idx; i < n - d + 1; i++) {
            maxi = max(maxi, jD[i]);
            ans = min(ans, maxi + memo(jD, n, i + 1, d - 1, dp));
        }

        return dp[idx][d] = ans;
    }

    int minDifficulty(vector<int>& jD, int d) {
        int n = jD.size();

        if (n < d) return -1;

        vector<vector<int>> dp(n, vector<int>(d + 1, -1));

        int ans = memo(jD, n, 0, d, dp);

        return ans;
    }
};