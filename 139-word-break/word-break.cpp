class Solution {
public:
    bool memo(string& s, int idx, vector<int>& dp, unordered_map<string, int>& mp) {
        int n = s.size();
        if (idx == n) return true;
        
        if (dp[idx] != -1) return dp[idx];
        
        string tmp = "";
        for (int i = idx; i < n; ++i) {
            tmp += s[i];
            if (mp.count(tmp) && memo(s, i + 1, dp, mp)) {
                return dp[idx] = true;
            }
        }
        
        return dp[idx] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> mp;

        for (const auto& str : wordDict) {
            mp[str]++;
        }
        
        int n = s.size();
        vector<int> dp(n, -1);
        
        return memo(s, 0, dp, mp);
    }
};