class Solution {
public:
    int partitionString(string s) {
        int ans = 0;
        vector<bool> seen(26, false);

        for (int i = 0; i < s.size(); ++i) {
            if (seen[s[i] - 'a']) {
                ans++;
                fill(seen.begin(), seen.end(), false);
            }
            seen[s[i] - 'a'] = true;
        }

        return ans + 1;
    }
};
