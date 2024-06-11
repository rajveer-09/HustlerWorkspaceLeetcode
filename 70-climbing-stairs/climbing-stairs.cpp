class Solution {
public:
    int fun(int n, vector<int>&dp){
        dp[0]=1;
        dp[1]=2;

        for(int i=2;i<n;i++){
            dp[i]=dp[i-2]+dp[i-1];
        }
        
        return dp[n-1];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        
        fun(n,dp);
        return dp[n-1];
    }
};