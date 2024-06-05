class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<vector<int>> v(words.size(), vector<int>(26, 0));
        char c;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            for (int i = 0; i < words.size(); i++) {
                string s = words[i];
                for (int j = 0; j < s.size(); j++) {
                    if (s[j] == ch)
                        v[i][ch - 'a']++;
                }
            }
        }
        vector<string> value;
        for (int j = 0; j < 26; j++) {
            int y = v[0][j];
            for (int i = 0; i < words.size(); i++) {
                y = min(y, v[i][j]);
            }
            if (y > 0) {
                for (int k = 1; k <= y; k++) {
                    c =(j+'a');
                    string str;
                    str.push_back(c);
                    value.push_back(str);
                }
            }
        }
        return value;
    }
};