class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return {};

        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), hash(n, -1);

        int maxLen = 1, lastIndex = 0;
        for(int i = 1; i < n; i++) {
            for(int prev = 0; prev < i; prev++) {
                if(nums[i] % nums[prev] == 0 && dp[prev] + 1 > dp[i]) {
                    dp[i] = dp[prev] + 1;
                    hash[i] = prev;
                }
            }
            if(dp[i] > maxLen) {
                maxLen = dp[i];
                lastIndex = i;
            }
        }

        vector<int> ans;
        while(lastIndex != -1) {
            ans.push_back(nums[lastIndex]);
            lastIndex = hash[lastIndex];
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};