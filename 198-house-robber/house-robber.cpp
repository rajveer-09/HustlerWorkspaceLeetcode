class Solution {
public:
    int fun(vector<int>& nums , vector<int> &dp){
        int n= nums.size();
        dp[n-1]= nums[n-1];
        dp[n-2]=max(dp[n-1], nums[n-2]);
        
        for(int i=n-3;i>=0;i--){
            
            if((nums[i]+dp[i+2])>=dp[i+1]){
                dp[i]=nums[i]+dp[i+2];
            }
            else{
                dp[i]= dp[i+1];
            }

        }

        return dp[0];

    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);

        vector<int>dp(n, -1);
        return fun(nums, dp);
    }
};

