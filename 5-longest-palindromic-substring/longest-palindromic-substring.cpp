class Solution {
public:
    int dp[1001][1001];
    bool isPalindrome(string &s, int i, int j) {
        if (i >= j) return true;
        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] != s[j]) return dp[i][j] = 0;
        return dp[i][j] = isPalindrome(s, i+1, j-1);
    }
    string longestPalindrome(string s) {
        memset(dp, -1, sizeof(dp));

        int n = s.size();
        string ans = s.substr(0, 1);
        int maxLen = 1;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(isPalindrome(s, i, j)){
                    int length = j - i + 1;
                    if(length > maxLen){
                        maxLen = length;
                        ans = s.substr(i, length);
                    } 
                }
            }
        }
        return ans;
    }
};
