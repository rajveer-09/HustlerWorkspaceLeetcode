class Solution {
public:
    bool solve (vector<int>& arr, int index, vector<int>& dp) {

        if(index >= arr.size()) return false;

        if (dp[index] != -1) return dp[index];
        
        if (arr[index] == 0) return dp[index] = true;

        
        dp[index] = 0;

        bool left = (index - arr[index] >= 0) && solve(arr, index - arr[index], dp);
        bool right = (index + arr[index] < arr.size()) && solve(arr, index + arr[index], dp);

        return dp[index] = (left || right);
    }

    bool canReach(vector<int>& arr, int start) {
        vector<int> dp(arr.size(), -1);
        return solve(arr, start, dp);
    }
};
