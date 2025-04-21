class Solution {
public:
    int partitionString(string s) {
        int ans = 0;
        int mask = 0;

        for (char c : s) {
            int bit = c - 'a';

            if (mask & (1 << bit)) {
                ans++;
                mask = 0;
            }

            mask |= (1 << bit);
        }

        return ans + 1;
    }
};