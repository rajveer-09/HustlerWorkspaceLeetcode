class Solution {
public:
    // Rabin Carp Algorithm
    int strStr(string txt, string pat) {
        int n = pat.length();
        int m = txt.length();

        int p = 7, mod = 101;
        
        int hashPat = 0, hashText = 0;
        int pRight = 1, pLeft = 1;

        for(int i = 0; i < n; i++) {
            hashPat = (hashPat + ((pat[i] - 'a' + 1) * pRight) % mod) % mod;
            hashText = (hashText + ((txt[i] - 'a' + 1) * pRight) % mod) % mod;
            pRight = (pRight * p) % mod;
        }

        for(int i = 0; i <= m - n; i++) {
            if(hashPat == hashText) {
                if(txt.substr(i, n) == pat) return i;
            }

            hashText = (hashText - ((txt[i] - 'a' + 1) * pLeft) % mod + mod) % mod;
            hashText = (hashText + ((txt[i + n] - 'a' + 1) * pRight) % mod) % mod;
            
            hashPat = (hashPat * p) % mod;
            pLeft = (pLeft * p) % mod;
            pRight = (pRight * p) % mod;
        }

        return -1;
    }
};