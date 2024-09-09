class Solution {
public:
    bool memo(vector<int>& arr, int idx, int sum, vector<vector<int>>& dp) {
        // Base Case
        if (sum == 0) return true;
        if (idx >= arr.size() || sum < 0) return false;
        
        if (dp[sum][idx] != -1) return dp[sum][idx];
        
        bool inc = memo(arr, idx + 1, sum - arr[idx], dp);
        bool exc = memo(arr, idx + 1, sum, dp);
        
        return dp[sum][idx] = (inc || exc);
    }
    bool canPartition(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if(sum %2 !=0) return false;
        else sum = sum/2;

        int n = arr.size();
        vector<vector<int>> dp(sum + 1, vector<int>(n, -1));
        
        return memo(arr, 0, sum, dp);
    }
};