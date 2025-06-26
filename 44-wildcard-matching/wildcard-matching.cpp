class Solution {
    public:
    vector<vector<int>> dp;
    bool dfs(int i, int j, string &s, string &p) {
        if (j == p.size()) return i == s.size();
        if (i == s.size()) {
            // p[j:] must be all '*'
            for (int k = j; k < p.size(); k++){
                if (p[k] != '*') return false;
            }
                
            return true;
        }
        if (dp[i][j] != -1) return dp[i][j];

        bool ans = false;
        if (p[j] == s[i] || p[j] == '?') {
            ans = dfs(i+1, j+1, s, p);
        } 
        else if (p[j] == '*') {
            // match zero chars (*) or one char (*)
            ans = dfs(i+1, j, s, p) || dfs(i, j+1, s, p);
        } 
        else {
            ans = false;
        }

        return dp[i][j] = ans;
    }

    bool isMatch(string s, string p) {
        dp.assign(s.size()+1, vector<int>(p.size()+1, -1));
        return dfs(0, 0, s, p);
    }
};
