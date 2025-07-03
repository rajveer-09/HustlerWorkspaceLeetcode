class Solution {
public:
    set<int> cols, diag1, diag2;

    void solve(int n, int i, vector<string>& row, vector<vector<string>>& chess){
        if(i == n){
            chess.push_back(row);
            return;
        }

        for(int c = 0; c < n; c++){
            if(cols.count(c) || diag1.count(i - c) || diag2.count(i + c)){
                continue;
            }

            cols.insert(c);
            diag1.insert(i - c);
            diag2.insert(i + c);
            row[i][c] = 'Q';

            solve(n, i + 1, row, chess);

            cols.erase(c);
            diag1.erase(i - c);
            diag2.erase(i + c);
            row[i][c] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> chess;
        string s(n, '.');

        vector<string> row(n, s);

        solve(n, 0, row, chess);
        
        return chess;
    }
};