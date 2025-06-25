class Solution {
public:
    int dp[1001][1001]; // -1 = unknown, 1 = palindrome, 0 = not palindrome
    
    bool isPalindrome(string &s, int i, int j) {
        if (i >= j) return true;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] != s[j]) return dp[i][j] = false;

        return dp[i][j] = isPalindrome(s, i+1, j-1);
    }

    int countSubstrings(string s) {
        memset(dp, -1, sizeof(dp));

        int n = s.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                ans += isPalindrome(s, i, j);
            }
        }

        return ans;
    }
};