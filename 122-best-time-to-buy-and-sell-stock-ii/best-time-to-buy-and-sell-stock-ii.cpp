class Solution{
private:
    int dp[100005][3];
    int func(int ind, int buy, int n, vector<int> &arr) {
        if (ind == n) {
            return 0;
        }
        if (dp[ind][buy] != -1) {
            return dp[ind][buy];
        }
        int profit = 0;
        if (buy == 0) { 
            profit = max(0 + func(ind + 1, 0, n, arr), (-1)*arr[ind] + func(ind + 1, 1, n, arr));
        }
        if (buy == 1) { 
            profit = max(0 + func(ind + 1, 1, n, arr), arr[ind] + func(ind + 1, 0, n, arr));
        }
        return dp[ind][buy] = profit;
    }
public:
    int maxProfit(vector<int> &arr) {
        int n = arr.size();
        if (n == 0) return 0;
            
        memset(dp, -1, sizeof(dp));
        int ans = func(0, 0, n, arr);
        return ans;
    }
};
