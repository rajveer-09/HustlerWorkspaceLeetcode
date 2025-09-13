class Solution {
public:
    int longestValidParentheses(const string& s) {
        int n = (int)s.size();
        vector<int> dp(n, 0);
        int max_len = 0;

        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    // Case: "..."
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } 
                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    // Case: "....))"
                    dp[i] = dp[i - 1] + 2 + ((i - dp[i - 1] - 2) >= 0 ? dp[i - dp[i - 1] - 2] : 0);
                }

                max_len = max(max_len, dp[i]);
            }
        }

        return max_len;
    }
};