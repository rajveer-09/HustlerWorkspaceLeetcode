class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int freq[3] = {0, 0, 0}; // {a, b, c}
        int start = 0;
        int ans = 0;

        for (int end = 0; end < n; end++) {
            freq[s[end] - 'a']++;

            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                ans += (n - end); // all substrings ending from end to n-1 are valid
                freq[s[start] - 'a']--;

                start++;
            }
        }

        return ans;
    }
};
