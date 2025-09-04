class Solution {
public:
    bool solve(int idx, string& s, unordered_set<string>& st, vector<int>& dp){
        if(idx == s.size()) return true;
        if(dp[idx] != -1) return dp[idx];

        for(int len = 1; len <= s.size() - idx; len++){
            string part = s.substr(idx, len);
            if(st.count(part) && solve(idx + len, s, st, dp)){
                return dp[idx] = true;
            }
        }
        
        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);

        return solve(0, s, st, dp);
    }
};
