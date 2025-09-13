class Solution {
public:
    int longestValidParentheses(const string& s) {
        int left = 0, right = 0, max_len = 0;

        // Left to right scan
        for (char c : s) {
            if (c == '(') {
                left++;
            } else {
                right++;
            }

            if (left == right) {
                max_len = max(max_len, 2 * right);
            } else if (right > left) {
                left = right = 0;
            }
        }

        left = right = 0;

        // Right to left scan
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }

            if (left == right) {
                max_len = max(max_len, 2 * left);
            } else if (left > right) {
                left = right = 0;
            }
        }

        return max_len;
    }
};