class Solution {
public:
    int dp[10001];
    int memo(int n){
        if(n == 0) return 0;

        if(dp[n] != -1) return dp[n];

        long long ans = INT_MAX;

        for(int i = 1; i * i <= n; i++){
            ans = min(ans, 1LL + memo(n - i * i));
        }

        return dp[n] = (int)ans;
    }
    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));

        return memo(n);
    }
};