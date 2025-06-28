class Solution {
    int dp[102][102];

    int func(int i, int j, vector<int> &cuts) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;
        for (int ind = i; ind <= j; ind++) {
            int ans = cuts[j + 1] - cuts[i - 1] + func(i, ind - 1, cuts) + func(ind + 1, j, cuts);
            mini = min(mini, ans);
        }
        return dp[i][j] = mini;
    }

public:
    int minCost(int n, vector<int> &cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        memset(dp, -1, sizeof(dp));
        return func(1, c, cuts);
    }
};