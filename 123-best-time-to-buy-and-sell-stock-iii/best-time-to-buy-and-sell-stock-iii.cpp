class Solution{
private:
    int dp[100001][2][3];
    int func(int ind, int buy, int cap, int n, vector<int> &arr) {
        if (ind == n || cap == 0) {
            return 0;
        }
        if (dp[ind][buy][cap] != -1) {
            return dp[ind][buy][cap];
        }
        int profit = 0;
        if (buy == 0) { 
            profit = max(0 + func(ind + 1, 0, cap, n, arr), 
                (-1)*arr[ind] + func(ind + 1, 1, cap, n, arr));
        }
        if (buy == 1) { 
            profit = max(0 + func(ind + 1, 1, cap, n, arr), 
                arr[ind] + func(ind + 1, 0, cap-1, n, arr));
        }
        return dp[ind][buy][cap] = profit;
    }
public:
    int maxProfit(vector<int> &arr) {
        int n = arr.size();
        if (n == 0) return 0;
            
        memset(dp, -1, sizeof(dp));
        int ans = func(0, 0, 2, n, arr);
        return ans;
    }
};
