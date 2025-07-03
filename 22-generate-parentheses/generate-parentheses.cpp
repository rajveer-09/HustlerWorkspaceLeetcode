class Solution {
public:
    void rec(int n, vector<string>& ans, string &s, int open){
        if(s.size() == n * 2 && open == 0){
            ans.push_back(s);
            return;
        }

        if(s.size() > n * 2) return;

        // place '('
        s += '(';
        rec(n, ans, s, open + 1);
        s.pop_back();
        
        // place ')'
        if(open > 0){
            s += ')';
            rec(n, ans, s, open - 1);
            s.pop_back();
        }

 
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";

        rec(n, ans, s, 0);

        return ans;
    }
};