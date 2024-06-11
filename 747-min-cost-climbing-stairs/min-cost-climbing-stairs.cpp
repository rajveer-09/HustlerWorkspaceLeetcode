class Solution {
public:
int fun(vector<int>& cost , vector<int> &dp){
    int n = cost.size();
    dp[n-1]= cost[n-1];
    dp[n-2]= cost[n-2];

    for(int i=n-3;i>=0;i--){
        int m = min(dp[i+1], dp[i+2]);
        dp[i] = m + cost[i];
    }

    return min(dp[0],dp[1]);
}
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);

        return fun(cost, dp);
    }
};