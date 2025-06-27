class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();

        for (auto& c : cuboids) sort(c.begin(), c.end()); // sort dimensions
        sort(cuboids.begin(), cuboids.end());             // sort cuboids

        vector<int> dp(n);
        int maxH = 0;

        for (int i = 0; i < n; ++i) {
            dp[i] = cuboids[i][2]; // take current height
            for (int j = 0; j < i; ++j) {
                if (cuboids[j][0] <= cuboids[i][0] &&
                    cuboids[j][1] <= cuboids[i][1] &&
                    cuboids[j][2] <= cuboids[i][2]) {
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                }
            }
            maxH = max(maxH, dp[i]);
        }

        return maxH;
    }
};