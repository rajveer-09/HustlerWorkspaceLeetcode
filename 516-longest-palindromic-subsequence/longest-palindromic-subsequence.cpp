class Solution {
public:
    int dp[1001][1001];
    int solve(string& s1, string& s2, int i, int j){
        if(i >= s1.size() || j >= s2.size()){
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + solve(s1, s2, i + 1, j + 1);
        }

        int op1 = solve(s1, s2, i + 1, j);
        int op2 = solve(s1, s2, i, j + 1);

        return dp[i][j] = max(op1, op2);
    }
    int longestPalindromeSubseq(string s) {
        memset(dp, -1, sizeof(dp));
        string s2 = s;
        reverse(s2.begin(), s2.end());

        return solve(s, s2, 0, 0);
    }
};