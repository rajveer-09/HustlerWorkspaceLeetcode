class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
         int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        // Fill DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        int lcsLength = dp[m][n];
        int i = m, j = n;
        string lcs = "";
        while (i > 0 && j > 0) {
            if (s1[i-1] == s2[j-1]) {
                lcs.push_back(s1[i-1]);
                i--;
                j--;
            } 
            else if (dp[i-1][j] > dp[i][j-1]) {
                i--;
            } else {
                j--;
            }
        }

        reverse(lcs.begin(), lcs.end());

        i=0, j=0;
        int idx = 0;
        string ans = "";
        while(i <s1.size() && j < s2.size() && idx < lcs.size()){
            if(s1[i] != lcs[idx]){
                ans += s1[i++];
            }
            if(s2[j] != lcs[idx]){
                ans += s2[j++];
            }
            if(s1[i] == lcs[idx] && s2[j] == lcs[idx]){
                ans += lcs[idx];
                idx++;
                i++;
                j++;
            }
        }

        while(i < s1.size()) ans+= s1[i++];
        while(j < s2.size()) ans+= s2[j++];

        return ans;
    }
};