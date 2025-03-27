class Solution {
public:
    int kam (vector<int>&dp , int  i, int  n){
        if(i==n){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int r1=0,r2=0;
        r1=kam(dp,i+1,n);
        if(i+2<=n){
           r2=kam(dp,i+2,n);
        }
        
        return dp[i]=r1+r2 ;
    }
    int climbStairs(int n) {
        if(n==1){
            return 1;
        }
        vector<int>dp(n+1,-1);
        return kam(dp,0,n);
    }
};