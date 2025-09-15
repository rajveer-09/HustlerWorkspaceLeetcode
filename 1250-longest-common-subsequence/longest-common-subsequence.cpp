class Solution {
public:
    int dp[1001][1001];
    int solve(string& s1, string& s2, int i, int j){
        if(i >= s1.size() || j >= s2.size()){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];

        // agar dono ke character same huye toh...
        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + solve(s1, s2, i + 1, j + 1);
        }

        // agr diff huye toh 2 options hai hmare paas...
        int op1 = solve(s1, s2, i + 1, j);
        int op2 = solve(s1, s2, i, j + 1);

        return dp[i][j] = max(op1, op2);
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));

        return solve(text1, text2, 0, 0);
    }
};