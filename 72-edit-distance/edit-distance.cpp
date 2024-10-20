class Solution {
public:
    int solve(string& a, string& b, int i, int j, vector<vector<int>>& dp){
        //base case : 
        if(i == a.size()) return b.size() - j;
        if(j == b.size()) return a.size() - i;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;

        if(a[i] == b[j]){
            ans = solve(a, b, i+1, j+1, dp);
        }

        else{
            int ins = 1 + solve(a, b, i, j + 1, dp);
            int del = 1 + solve(a, b, i+1, j, dp);
            int rep = 1 + solve(a, b, i+1, j + 1, dp);

            ans = min({ins, del, rep});
        }

        return dp[i][j] = ans;
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int> (word2.size(), -1));

        return solve(word1, word2, 0, 0, dp);
    }
};