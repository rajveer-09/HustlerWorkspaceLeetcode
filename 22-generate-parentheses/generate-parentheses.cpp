class Solution {
public:
    void solve(int open, int close, string temp, vector<string>& ans, int n){
        if(open + close == 2 * n){
            ans.push_back(temp);
            return;
        }

        if(open < n){
            temp += '(';
            solve(open + 1, close, temp, ans, n);
            
            temp.pop_back();
        }
        if(close < n  && open > close){
            temp += ')';
            solve(open, close + 1, temp, ans, n);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";

        solve(0, 0, temp, ans, n);

        return ans;
    }
};