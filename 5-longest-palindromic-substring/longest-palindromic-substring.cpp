class Solution {
public:
    string longestPalindrome(string s) {
        ios_base::sync_with_stdio(false);
        int len = s.length();
        if (len < 2) {
            return s;
        }

        int start = 0;
        int maxLen = 1;

        int i = 0;
        while (i < len) {
            int l = i, r = i;
            while (r < len - 1 && s[r] == s[r + 1]) {
                r++;
            }
            i = r + 1;

            while (l > 0 && r < len - 1 && s[l - 1] == s[r + 1]) {
                l--;
                r++;
            }

            int curLen = r - l + 1;
            if (curLen > maxLen) {
                start = l;
                maxLen = curLen;
            }
        }

        return s.substr(start, maxLen);
    }
};
