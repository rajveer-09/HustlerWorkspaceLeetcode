class Solution {
public:
    bool solve(int idx1, int idx2, int idx3, string& s1, string& s2, string& s3, vector<vector<vector<int>>>& dp) {
        
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();

        if (idx1 == n1 && idx2 == n2 && idx3 == n3) {
            return true;
        }

        if (idx3 >= n3) {
            return false;
        }

        if (dp[idx1][idx2][idx3] != -1) {
            return dp[idx1][idx2][idx3];
        }

        bool result = false;

        if (idx1 < n1 && s1[idx1] == s3[idx3]) {
            result = solve(idx1 + 1, idx2, idx3 + 1, s1, s2, s3, dp);
        }

        if (result) {
            return dp[idx1][idx2][idx3] = result;
        }

        if (idx2 < n2 && s2[idx2] == s3[idx3]) {
            result = solve(idx1, idx2 + 1, idx3 + 1, s1, s2, s3, dp);
        }

        return dp[idx1][idx2][idx3] = result;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();

        if (n1 + n2 != n3) return false;

        vector<vector<vector<int>>> dp(n1 + 1, vector<vector<int>>(n2 + 1, vector<int>(n3 + 1, -1)));
        return solve(0, 0, 0, s1, s2, s3, dp);
    }
};