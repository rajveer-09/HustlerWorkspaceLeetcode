class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();

        // Edge case: if k is large enough to go straight
        if (k >= n + m - 2) return n + m - 2;

        vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(k + 1, false)));
        queue<tuple<int, int, int>> q; // x, y, remaining k

        q.push({0, 0, k});
        visited[0][0][k] = true;

        int steps = 0;
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [x, y, rem] = q.front(); q.pop();

                if (x == n - 1 && y == m - 1) return steps;

                for (auto [dx, dy] : dirs) {
                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                        int newRem = rem - grid[nx][ny];

                        if (newRem >= 0 && !visited[nx][ny][newRem]) {
                            visited[nx][ny][newRem] = true;
                            q.push({nx, ny, newRem});
                        }
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};
