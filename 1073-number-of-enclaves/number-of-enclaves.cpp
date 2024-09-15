class Solution{
public:
    void bfs(vector<vector<int>> &grid, int i, int j, vector<vector<bool>>& visited) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;
        grid[i][j] = 0;

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
                    if (!visited[xx][yy] && grid[xx][yy] == 1) {
                        q.push({xx, yy});
                        visited[xx][yy] = true;
                        grid[xx][yy] = 0;
                    }
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || j == 0 || i == n - 1 || j == m - 1){
                    if(!visited[i][j] && grid[i][j] == 1){
                        bfs(grid, i, j, visited);
                    }
                }
            }
        }

        int cnt = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) cnt++;
            }
        }

        return cnt;
    }
};
