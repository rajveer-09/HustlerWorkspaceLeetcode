class Solution {
public:
    vector<int> LPS(string& s){
        int n = s.size();
        vector<int> lps(n, 0);

        int i = 1, j = 0;
        // i se aage badh rha hu
        // j se start se dekh rha kitna equal hai
        while(i < n){
            if(s[i] == s[j]){
                lps[i] = j + 1;
                j++;
            }
            else{
                while(j > 0 && s[i] != s[j]) j = lps[j - 1];

                if(s[i] == s[j]){
                    lps[i] = j + 1;
                    j++;
                }
            }
            i++;
        }
        return lps;
    }
    string longestPrefix(string s) {
        vector<int>lps = LPS(s);

        return s.substr(0, lps[s.size() - 1]);
    }
};