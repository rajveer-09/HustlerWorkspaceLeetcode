class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, int> islandSize;
        int id = 2; // 0 = water, 1 = unvisited land, so start IDs from 2
        int maxIsland = 0;

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        function<int(int,int)> dfs = [&](int r, int c) {
            if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != 1) return 0;
            grid[r][c] = id;
            int size = 1;
            for (int k = 0; k < 4; k++) {
                size += dfs(r + dr[k], c + dc[k]);
            }
            return size;
        };

        // Step 1: Label islands & store sizes
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int size = dfs(i, j);
                    islandSize[id] = size;
                    maxIsland = max(maxIsland, size);
                    id++;
                }
            }
        }

        // Step 2: Try flipping each 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> neighbors;
                    for (int k = 0; k < 4; k++) {
                        int nr = i + dr[k], nc = j + dc[k];
                        if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] > 1) {
                            neighbors.insert(grid[nr][nc]);
                        }
                    }
                    int newSize = 1; // for the flipped cell
                    for (auto &nid : neighbors) {
                        newSize += islandSize[nid];
                    }
                    maxIsland = max(maxIsland, newSize);
                }
            }
        }

        return maxIsland;
    }
};
