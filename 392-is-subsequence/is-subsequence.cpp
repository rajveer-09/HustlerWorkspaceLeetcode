class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        while(i<s.length() && j<t.length()){
            if(t[j++]==s[i]) i++;
        }
        if(i==s.length()) return true;
        return false;
    }
};