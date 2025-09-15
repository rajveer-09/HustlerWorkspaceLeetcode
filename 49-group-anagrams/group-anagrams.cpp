class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (const string& s : strs) {
            string key = "";
            vector<int> count(26, 0);
            
            for (char c : s) {
                count[c - 'a']++;
            }

            for (int i = 0; i < 26; ++i) {
                key += to_string(count[i]) + '#';
            }

            groups[key].push_back(s);
        }
        
        vector<vector<string>> result;
        for (auto const& pair : groups) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};