class Solution {
public:
    long long maxi(vector<int>& a, vector<int>& b, int idx, int bdx, vector<vector<long long>>& dp) {
        int n = a.size();
        int m = b.size();

        if(bdx == n) return 0;

        if (idx >= m) return -1e11; 

        if (dp[idx][bdx] != -1e12) return dp[idx][bdx];

        long long take = (1LL*b[idx] )* a[bdx] + maxi(a, b, idx + 1, bdx + 1, dp);
        
        long long not_take = maxi(a, b, idx + 1, bdx, dp);

        return dp[idx][bdx] = max(take, not_take);
    }

    long long maxScore(vector<int>& a, vector<int>& b) {

        int n = a.size();
        int m = b.size();

        vector<vector<long long>> dp(m, vector<long long>(n, -1e12));

        return maxi(a, b, 0, 0, dp);
    }
};