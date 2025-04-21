class Solution {
private:
    vector<vector<int>> xtra, zero;
    int ret;

    void solve(int i, int count) {
        if (i >= zero.size()) {
            ret = min(ret, count);
            return;
        }

        for (int k = 0; k < xtra.size(); k++) {
            if (xtra[k][2] == 0) continue;

            xtra[k][2]--;
            solve(i + 1, abs(xtra[k][0] - zero[i][0]) + abs(xtra[k][1] - zero[i][1]) + count);
            xtra[k][2]++;
        }
    }

public:
    int minimumMoves(vector<vector<int>>& grid) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] == 0) {
                    zero.push_back({i, j});
                } 
                else if (grid[i][j] > 1) {
                    xtra.push_back({i, j, grid[i][j] - 1});
                }
            }
        }

        if (zero.size() == 0) return 0;

        ret = INT_MAX;

        solve(0, 0);
        
        return ret;
    }
};