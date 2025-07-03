class Solution {
public:
    set<pair<int, int>> used; //{i, j};
    void solve(int n, int i, vector<string>& row, vector<vector<string>>& chess){
        if(i == n){
            chess.push_back(row);
            return;
        }

        for(int c = 0; c < n; c++){
            bool flg = false;
            for(auto it : used){
                if(c == it.second || abs(i - it.first) == abs(c - it.second)){
                    flg = true;
                }
                
            }

            if(flg) continue;

            used.insert({i, c});
            row[i][c] = 'Q';
            solve(n, i + 1, row, chess);
            used.erase({i, c});
            row[i][c] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> chess;
        string s = "";
        for(int i = 0; i < n; i++) s += '.';

        vector<string> row(n, s);

        solve(n, 0, row, chess);

        return chess;
    }
};