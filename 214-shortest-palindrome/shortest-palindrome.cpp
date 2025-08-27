class Solution {
public:
    vector<int> computeLPS(string s) {
        int n = s.size();
        vector<int> LPS(n, 0);
        int i = 1, j = 0;

        while(i < n) {
            if(s[i] == s[j]) {
                LPS[i] = j+1;
                i++, j++;
            } else {
                while(j > 0 && s[i] != s[j]) {
                    j = LPS[j-1];
                }
                if(s[i] == s[j]) {
                    LPS[i] = j+1;
                    j++;
                }
                i += 1;
            }
        }
        return LPS;
    }

    string shortestPalindrome(string s) {
        string revs = s;
        reverse(revs.begin(), revs.end());

        string str = s + '$' + revs;
        vector<int> lps = computeLPS(str);

        int ans = s.size() - lps.back();

        string to_add = revs.substr(0, ans);

        return to_add + s;
    }
};