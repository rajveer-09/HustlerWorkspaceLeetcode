class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int openCount = 0;

        for (char c : s) {
            if (c == '(') {
                if (openCount > 0) {
                    ans += c;
                }
                openCount++;
            } else if (c == ')') {
                openCount--;
                if (openCount > 0) {
                    ans += c;
                }
            }
        }
        return ans;
    }
};