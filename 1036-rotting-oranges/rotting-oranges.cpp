class Solution {
public:
    int orangesRotting(vector<vector<int>> &grid) {
        int rows = grid.size();
        int cols = grid[0].size();
       
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<pair<int, int>, int>> rottenQueue;
        
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Enqueue all initially rotten oranges
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    rottenQueue.push({{i, j}, 0});
                    visited[i][j] = true;
                }
            }
        }

        int maxTime = 0;

        // Perform BFS to rot adjacent fresh oranges
        while (!rottenQueue.empty()) {
            int currentRow = rottenQueue.front().first.first;
            int currentCol = rottenQueue.front().first.second;
            int time = rottenQueue.front().second;

            maxTime = max(maxTime, time);
            rottenQueue.pop();

            // Check all four possible directions
            for (auto direction : directions) {
                int newRow = currentRow + direction.first;
                int newCol = currentCol + direction.second;

                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                    if (!visited[newRow][newCol] && grid[newRow][newCol] == 1) {
                        rottenQueue.push({{newRow, newCol}, time + 1});
                        visited[newRow][newCol] = true;
                    }
                }
            }
        }

        // Check if there's any fresh orange left unrotted
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!visited[i][j] && grid[i][j] == 1) return -1;
            }
        }

        return maxTime;
    }
};
