class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        // Sort dimensions within each cuboid
        for (auto& cuboid : cuboids) {
            sort(cuboid.begin(), cuboid.end());
        }
        
        // Sort all cuboids based on their dimensions
        sort(cuboids.begin(), cuboids.end(), [](const vector<int>& a, const vector<int>& b) {
            return tie(a[0], a[1], a[2]) < tie(b[0], b[1], b[2]);
        });

        int n = cuboids.size();
        vector<int> dp(n, 0);
        int maxHeight = 0;

        for (int i = 0; i < n; ++i) {
            dp[i] = cuboids[i][2];
            for (int j = 0; j < i; ++j) {
                if (cuboids[i][0] >= cuboids[j][0] &&
                    cuboids[i][1] >= cuboids[j][1] &&
                    cuboids[i][2] >= cuboids[j][2]) {
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                }
            }
            maxHeight = max(maxHeight, dp[i]);
        }

        return maxHeight;
    }
};
