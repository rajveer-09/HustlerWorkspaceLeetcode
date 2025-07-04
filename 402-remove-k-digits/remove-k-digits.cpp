class Solution {
public:
    string removeKdigits(string num, int k) {
        string stk;

        for (char digit : num) {
            while (!stk.empty() && k > 0 && stk.back() > digit) {
                stk.pop_back();
                k--;
            }
            stk.push_back(digit);
        }

        // Still need to remove digits?
        while (k-- > 0 && !stk.empty()) {
            stk.pop_back();
        }

        // Remove leading zeros.. eg. "0200"
        int i = 0;
        while (i < stk.size() && stk[i] == '0') i++;
        
        string result = stk.substr(i);

        return result.empty() ? "0" : result;
    }
};