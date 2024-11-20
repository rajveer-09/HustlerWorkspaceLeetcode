class Solution {
public:
    bool dfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<bool>>& vis) {
        int n = grid1.size();
        int m = grid1[0].size();

        if (i < 0 || i >= n || j < 0 || j >= m || grid2[i][j] != 1 || vis[i][j]) {
            return true;
        }

        vis[i][j] = true;

        bool checkval = (grid1[i][j] == grid2[i][j]);

        bool up = dfs(i - 1, j, grid1, grid2, vis);
        bool down = dfs(i + 1, j, grid1, grid2, vis);
        bool left = dfs(i, j - 1, grid1, grid2, vis);
        bool right = dfs(i, j + 1, grid1, grid2, vis);

        return checkval && up && down && left && right;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int cnt = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid2[i][j] == 1 && !vis[i][j]) {
                    if (dfs(i, j, grid1, grid2, vis)) {
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
};