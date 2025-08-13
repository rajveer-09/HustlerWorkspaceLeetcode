class Solution {
public:
    bool isDigit(char ch) {
        return ch >= '0' && ch <= '9';
    }

    int calculate(string s) {
        stack<int> stk;
        long long num = 0;
        char op = '+'; // previous operator

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if (isDigit(ch)) {
                num = num * 10 + (ch - '0');
            }

            // If current char is operator OR last char in string
            if ((!isDigit(ch) && ch != ' ') || i == s.size() - 1) {
                if (op == '+') {
                    stk.push(num);
                }
                else if (op == '-') {
                    stk.push(-num);
                }
                else if (op == '*') {
                    int top = stk.top(); stk.pop();
                    stk.push(top * num);
                }
                else if (op == '/') {
                    int top = stk.top(); stk.pop();
                    stk.push(top / num);
                }

                op = ch; // update operator
                num = 0;
            }
        }

        int ans = 0;
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        
        return ans;
    }
};