class Solution {
public:
    const int mod = 1e9 + 7;
    unordered_map<string, bool> mpp;

    long long countSubsequenceOccurrences(const string &pattern, const string &mainStr) {
        int n = mainStr.size();
        int m = pattern.size();
        vector<long long> dp(m + 1, 0);
        dp[0] = 1;

        for (char c : mainStr) {
            for (int j = m - 1; j >= 0; j--) {
                if (pattern[j] == c) {
                    dp[j + 1] = (dp[j + 1] + dp[j]) % mod;
                }
            }
        }
        return dp[m] % mod;
    }

    bool isPalindrome(const string &s) {
        if (mpp.count(s)) return mpp[s];
        int i = 0, j = (int)s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) return mpp[s] = false;
        }
        return mpp[s] = true;
    }

    void generateAllPalindromes(vector<string> &ans) {
        for (char a = '0'; a <= '9'; a++) {
            for (char b = '0'; b <= '9'; b++) {
                for (char c = '0'; c <= '9'; c++) {
                    string p;
                    p.push_back(a);
                    p.push_back(b);
                    p.push_back(c);
                    p.push_back(b);
                    p.push_back(a);
                    ans.push_back(p);
                }
            }
        }
    }


    int countPalindromes(string s) {
        vector<string> allPossible;
        generateAllPalindromes(allPossible);

        long long cnt = 0;
        for (string &ss : allPossible) {
            cnt = (cnt + countSubsequenceOccurrences(ss, s)) % mod;
        }
        return (int)cnt;
    }
};
