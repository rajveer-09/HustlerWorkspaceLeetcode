class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        long long num = 0;
        int sign = 1;

        // Step 1: Skip leading whitespaces
        while (i < n && s[i] == ' ') i++;

        // Step 2: Check sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Parse digits
        while (i < n && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');

            // Step 4: Clamp if overflow
            if (sign == 1 && num > INT_MAX) return INT_MAX;
            if (sign == -1 && -num < INT_MIN) return INT_MIN;

            i++;
        }

        return sign * num;
    }
};
