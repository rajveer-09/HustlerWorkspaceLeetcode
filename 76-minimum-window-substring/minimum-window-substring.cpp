class Solution {
public:
    bool check(unordered_map<char, int>& mp){
        for(auto& it : mp){
            if(it.second > 0) return false;
        }

        return true;
    }
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;

        for(char it : t) mp[it]++;

        int st = 0;
        int ans = INT_MAX;
        int start = 0;

        for (int i = 0; i < s.size(); i++) {
            if (mp.find(s[i]) != mp.end()) {
                mp[s[i]]--;
            }

            while (check(mp)) {
                if (ans > i - st + 1) {
                    ans = i - st + 1;
                    start = st;
                }
                if (mp.find(s[st]) != mp.end()) {
                    mp[s[st]]++;
                }
                
                st++;
            }
        }

        if (ans == INT_MAX) return "";

        return s.substr(start, ans);
    }
};