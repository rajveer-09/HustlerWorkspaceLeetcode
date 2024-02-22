class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans = "", temp = "";
        int i = 0, j = 0;
        while(i < k && j <= s.size())
        {
            if(s[j] != ' ')
                temp += s[j];
            else
            {
                ans += temp;
                temp = "";
                if(i < k - 1)
                    ans += ' ';
                i++;
            }
            if(j == s.size() - 1)
                ans += temp;
            j++;
        }    
        return ans;
    }
};