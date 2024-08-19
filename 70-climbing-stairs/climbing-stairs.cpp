class Solution {
public:
    int fun(int n, vector<int>& dp) {
        if (n <= 1) return 1;

        if (dp[n] != -1) return dp[n];
        
        int take_prev = fun(n - 1, dp);
        int not_takeprev = (n >= 2) ? fun(n - 2, dp) : 0;

        dp[n] = take_prev + not_takeprev;

        return dp[n];
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1); 
        return fun(n, dp); 
    }
};
