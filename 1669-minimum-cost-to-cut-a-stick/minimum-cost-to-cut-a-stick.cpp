class Solution{
private:
    int func(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
        /* Base case: If i is greater than 
        j, there are no cuts to consider.*/
        if (i > j) {
            return 0;
        }
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int mini = INT_MAX;

        for (int ind = i; ind <= j; ind++) {
            /* Calculate the cost for
            making a cut at position 'ind'.*/
            int ans = cuts[j + 1] - cuts[i - 1] + func(i, ind - 1, cuts, dp) + func(ind + 1, j, cuts, dp);

            mini = min(mini, ans);
        }
        return dp[i][j] = mini;
    }
public:
    int minCost(int n, vector<int> &cuts) {
        int c = cuts.size();
        /* Modify the cuts array by adding 0 
        at the beginning and 'n' at the end.*/
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        
        vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));

       return func(1, c, cuts, dp);
    }
};