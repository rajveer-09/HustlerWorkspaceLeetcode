class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        for(auto &i:nums) i%=k;
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int>(k, 0));
        vector<int> last(k,-1);

        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                if(last[j]==-1) dp[i][j] = 1;
                else dp[i][j] = dp[ last[j] ][ nums[i] ] + 1;
                ans=max(ans, dp[i][j]);
            }
            last[nums[i]] = i;
        }
        return ans;
    }
};