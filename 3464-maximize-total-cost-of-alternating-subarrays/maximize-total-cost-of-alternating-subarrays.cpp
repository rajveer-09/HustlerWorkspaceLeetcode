class Solution {
public:
    long dp[100001][2];
    long helper(int ind, int n, vector<int>& nums, bool ch){
        if(ind == n)
            return 0;
        if(dp[ind][ch] != LONG_MIN)
            return dp[ind][ch];
        long maxi = LONG_MIN;
        maxi = ((!ch) ? nums[ind] : -1 * nums[ind]) + helper(ind + 1, n, nums, !ch);
        maxi = max(maxi, nums[ind] + helper(ind + 1, n, nums, true));
        return dp[ind][ch] = maxi;
    }
    
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < 100001 ; i++){
            for(int j = 0 ; j < 2 ; j++)
                dp[i][j] = LONG_MIN;
        }
        return helper(0, n, nums, false);
    }
};