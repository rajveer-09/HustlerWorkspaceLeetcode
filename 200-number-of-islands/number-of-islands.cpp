#pragma GCC optimize("O3,unroll-loops")

static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    return true;
}();
class Solution {
public:
    void bfs(vector<vector<char>> &grid, int i, int j, vector<vector<bool>>& visited) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            // Directions for moving up, down, left, and right
            vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

            for (auto dir : directions) {
                int xx = x + dir.first;
                int yy = y + dir.second;

                if (xx >= 0 && xx < n && yy >= 0 && yy < m) {
                    if (!visited[xx][yy] && grid[xx][yy] == '1') {
                        q.push({xx, yy});
                        visited[xx][yy] = true;
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>> &grid) {
        ios_base::sync_with_stdio(false);
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    cnt++;
                    bfs(grid, i, j, visited);
                }
            }
        }

        return cnt;
    }
};
