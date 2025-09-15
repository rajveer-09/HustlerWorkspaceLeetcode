class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n + 1, 1e9);
        dp[0] = 0;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j * j <= n; j++){
                if(i - j * j >= 0){
                    dp[i] = min(dp[i], 1 + dp[i - j * j]);
                }
            }
        }
        
        if(dp[n] >= 1e9) return -1;
        
        return dp[n];
    }
};