class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        dist[0][0] = grid[0][0];
        pq.push({dist[0][0], {0, 0}});

        while (!pq.empty()) {
            auto [time, pos] = pq.top();
            auto [r, c] = pos;
            pq.pop();

            if (r == n - 1 && c == n - 1) {
                return time;
            }

            if (time > dist[r][c]) {
                continue;
            }

            for (auto& d : dir) {
                int nr = r + d.first;
                int nc = c + d.second;

                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    int newTime = max(time, grid[nr][nc]);

                    if (newTime < dist[nr][nc]) {
                        dist[nr][nc] = newTime;
                        pq.push({newTime, {nr, nc}});
                    }
                }
            }
        }
        
        return -1;
    }
};