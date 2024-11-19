class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> mp;
        for (char it : t) mp[it]++;

        int start = 0, minLength = INT_MAX, left = 0;
        int count = t.size();

        for (int right = 0; right < s.size(); ++right) {
            if (mp[s[right]] > 0) count--;
            mp[s[right]]--;

            while (count == 0) {
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    start = left;
                }
                mp[s[left]]++;
                if (mp[s[left]] > 0) {
                    count++;
                }
                left++;
            }
        }
        if (minLength == INT_MAX) return "";

        return s.substr(start, minLength);
    }
};