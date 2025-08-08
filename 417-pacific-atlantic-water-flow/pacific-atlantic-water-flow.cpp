class Solution {
public:
    int m, n;
    vector<vector<bool>> pac, atl;
    vector<vector<int>> res;
    vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    bool isValid(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    void dfs(int i, int j, vector<vector<int>>& h, vector<vector<bool>>& visited) {
        visited[i][j] = true;
        for (auto& d : dir) {
            int x = i + d[0];
            int y = j + d[1];
            if (isValid(x, y) && !visited[x][y] && h[x][y] >= h[i][j]) {
                dfs(x, y, h, visited);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        pac.assign(m, vector<bool>(n, false));
        atl.assign(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            dfs(i, 0, heights, pac);
            dfs(i, n - 1, heights, atl);
        }
        for (int j = 0; j < n; j++) {
            dfs(0, j, heights, pac);
            dfs(m - 1, j, heights, atl);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pac[i][j] && atl[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};