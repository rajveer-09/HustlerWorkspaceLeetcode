class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left, star;
        // storing index

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                left.push(i);
            } 
            else if (s[i] == '*') {
                star.push(i);
            } 
            else { // ')'
                if (!left.empty()) {
                    left.pop();
                } 
                else if (!star.empty()) {
                    star.pop();
                } 
                else {
                    return false;
                }
            }
        }
        // Match remaining '(' with '*'
        while (!left.empty() && !star.empty()) {
            if (left.top() > star.top()) return false; // order invalid
            left.pop();
            star.pop();
        }

        return left.empty();
    }
};
