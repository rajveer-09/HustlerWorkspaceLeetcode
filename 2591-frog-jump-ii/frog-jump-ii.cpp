class Solution {
public:
    int maxJump(vector<int>& stones) {
        int ans;
        int n = stones.size();
        ans = stones[1] - stones[0];
        for (int i = 2; i < n; i += 2) {
            ans = max(ans, stones[i] - stones[i - 2]);
        }
        for (int i = 3; i < n; i += 2) {
            ans = max(ans, stones[i] - stones[i - 2]);
        }
        return ans;
    }
};