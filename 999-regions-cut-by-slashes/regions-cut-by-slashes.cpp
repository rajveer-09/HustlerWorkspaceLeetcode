class Solution {
public:
    void dfs(vector<vector<int>>& g, int i, int j, int n) {
        if (i < 0 || i >= n || j < 0 || j >= n || g[i][j] == 1) {
            return;
        }
        g[i][j] = 1;

        dfs(g, i + 1, j, n);
        dfs(g, i - 1, j, n);
        dfs(g, i, j + 1, n);
        dfs(g, i, j - 1, n);
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> g(n * 3, vector<int>(n * 3, 0));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '/') {
                    g[i * 3][j * 3 + 2] = 1;
                    g[i * 3 + 1][j * 3 + 1] = 1;
                    g[i * 3 + 2][j * 3] = 1;
                } 
                else if (grid[i][j] == '\\') {
                    g[i * 3][j * 3] = 1;
                    g[i * 3 + 1][j * 3 + 1] = 1;
                    g[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }
        
        int regions = 0;
        for (int i = 0; i < n * 3; ++i) {
            for (int j = 0; j < n * 3; ++j) {
                if (g[i][j] == 0) {
                    regions++;
                    dfs(g, i, j, n * 3);
                }
            }
        }
        return regions;
    }
    
};