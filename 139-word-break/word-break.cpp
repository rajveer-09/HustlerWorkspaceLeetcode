class Solution {
public:
    // bool solve(int idx, string& s, unordered_set<string>& st, vector<int>& dp){
    //     if(idx == s.size()) return true;
    //     if(dp[idx] != -1) return dp[idx];

    //     for(int len = 1; len <= s.size() - idx; len++){
    //         string part = s.substr(idx, len);
    //         if(st.count(part) && solve(idx + len, s, st, dp)){
    //             return dp[idx] = true;
    //         }
    //     }
        
    //     return dp[idx] = false;
    // }

    // bool wordBreak(string s, vector<string>& wordDict) {
    //     unordered_set<string> st(wordDict.begin(), wordDict.end());
    //     vector<int> dp(s.size(), -1);

    //     return solve(0, s, st, dp);
    // }

    bool wordBreak(string s, vector<string>& wordDict) {
        // unordered_set -> O(1) average time complexity lookups
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                // dp[j] is true, meaning s[0...j-1] can be segmented
                // s.substr(j, i-j) is a word in the dictionary
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};
