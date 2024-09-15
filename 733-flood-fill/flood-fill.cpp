class Solution{
    public:
    void bfs(vector<vector<int>> &grid, int i, int j, int newColor, vector<vector<bool>>& visited) {
        int n = grid.size();
        int m = grid[0].size();

        int val = grid[i][j];

        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;
        grid[i][j] = newColor;

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
                    if (!visited[xx][yy] && grid[xx][yy] == val) {
                        q.push({xx, yy});
                        visited[xx][yy] = true;
                        grid[xx][yy] = newColor;
                    }
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &images,
                                  int sr, int sc, int newColor) {
        int n = images.size();
        int m = images[0].size();

        vector<vector<int>> image = images;

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        bfs(image, sr, sc,newColor, visited);

        return image;
    }
};