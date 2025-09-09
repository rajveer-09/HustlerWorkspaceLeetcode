class Solution {
public:
    struct State {
        string cur;
        int open, close;
    };

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        queue<State> q;
        q.push({"", 0, 0});

        while (!q.empty()) {
            State s = q.front(); q.pop();

            if (s.cur.size() == 2 * n) {
                ans.push_back(s.cur);
                continue;
            }

            if (s.open < n) {
                q.push({s.cur + "(", s.open + 1, s.close});
            }
            if (s.close < s.open) {
                q.push({s.cur + ")", s.open, s.close + 1});
            }
        }
        return ans;
    }
};
