class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        int freshCount = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } 
                else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        if (freshCount == 0) return 0;

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool hasRotten = false;

            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();

                for (auto dir : directions) {
                    int xx = x + dir.first;
                    int yy = y + dir.second;

                    if (xx >= 0 && xx < n && yy >= 0 && yy < m && grid[xx][yy] == 1){
                        grid[xx][yy] = 2;
                        q.push({xx, yy});
                        freshCount--;
                        hasRotten = true;
                    }
                }
            }

            if (hasRotten) {
                time++;
            }
            else{
                break;
            }
        }

        return freshCount == 0 ? time : -1;
    }
};