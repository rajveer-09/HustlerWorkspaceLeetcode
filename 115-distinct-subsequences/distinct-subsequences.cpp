class Solution {
public:
    long long dp[1001][1001];
    long long dfs(int i, int j, string &s, string &t) {
        if (j == t.size()) return 1;
        if (i == s.size()) return 0;

        if (dp[i][j] != -1) return dp[i][j];
        
        long long ans = dfs(i+1, j, s, t); // not_take

        if (s[i] == t[j]) {
            ans += dfs(i+1, j+1, s, t); // take
        }
        return dp[i][j] = ans;
    }

    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof(dp));

        return (int)dfs(0, 0, s, t);
    }
};
