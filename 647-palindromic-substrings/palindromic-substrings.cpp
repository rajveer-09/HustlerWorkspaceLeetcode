class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;

        for (int i = 0; i < n; ++i) {
            // Odd length palindromes
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                count++;
                l--;
                r++;
            }

            // Even length palindromes
            l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                count++;
                l--;
                r++;
            }
        }
        
        return count;
    }
};