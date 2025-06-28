class Solution {
public:
    int dp[501][501];
    int solve(int i, int j, int k, vector<int>& arr){
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int sum = 0;
        int maxi = -1;

        for(int p = i; p <= j && p < i + k; p++){
            maxi = max(arr[p], maxi);
            sum = max(sum, solve(p + 1, j, k, arr) + (p - i + 1) * maxi);
        }

        return dp[i][j] = sum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp, -1, sizeof(dp));
        int n = arr.size();

        return solve(0, n - 1, k, arr);
    }
};