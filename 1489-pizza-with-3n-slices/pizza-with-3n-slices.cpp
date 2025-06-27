class Solution {
public:
    int dp[501][501];

    int solve(int i, int k, vector<int>& slices) {
        if (k == 0) return 0;
        if (i >= slices.size()) return 0;

        if (dp[i][k] != -1) return dp[i][k];

        // Either take current slice and skip next (i+2), or skip current (i+1)
        int take = slices[i] + solve(i + 2, k - 1, slices);
        int notTake = solve(i + 1, k, slices);

        return dp[i][k] = max(take, notTake);
    }

    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        int pick = n / 3;

        memset(dp, -1, sizeof(dp));
        vector<int> case1(slices.begin(), slices.end() - 1);
        int ans1 = solve(0, pick, case1);

        memset(dp, -1, sizeof(dp));
        vector<int> case2(slices.begin() + 1, slices.end());
        int ans2 = solve(0, pick, case2);

        return max(ans1, ans2);
    }
};
