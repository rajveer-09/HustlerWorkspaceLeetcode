class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<vector<int>>dp(k+1,vector<int>(n));
        for(int i=0;i<n;i++) {
            dp[0][i]=1;
        }
        int mod=1e9+7;
        for(int i=1;i<=k;i++) {
            dp[i][0]=1;
            for(int j=1;j<n;j++) {
                dp[i][j]=((dp[i][j-1])%mod+(dp[i-1][j])%mod)%mod;
            }
        }
        return dp[k][n-1]%mod;
    }
};