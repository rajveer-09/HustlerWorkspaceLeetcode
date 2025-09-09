class Solution {
public:
    void solve(string& digits, int idx, string& tmp, vector<string>& ans, vector<string>& keyboard){
        if(idx >= digits.size()) {
            if(tmp.size()) ans.push_back(tmp);
            return;
        }

        int button = digits[idx] - '0';

        for(int i = 0; i < keyboard[button].size(); i++){
            tmp += keyboard[button][i];

            solve(digits, idx + 1, tmp, ans, keyboard);

            tmp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(!digits.size()) return {};
        
        vector<string>keyboard{
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> ans {""};
        // string temp = "";

        // solve(digits, 0, temp, ans, keyboard);

        for(char ch : digits){
            vector<string> temp;
            for(string& a : ans){
                for(char c : keyboard[ch - '0']){
                    temp.push_back(a + c);
                }
            }

            ans = temp;
        }

        return ans;
    }
};