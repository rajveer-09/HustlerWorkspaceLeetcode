class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        // minimum problem se pahuchna hai

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], 0, 0});

        int directions[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};


        while(!pq.empty()){
            auto [h, r, c] = pq.top(); pq.pop();

            if(h > health) continue;

            for(auto dir : directions){
                int x = dir[0] + r;
                int y = dir[1] + c;

                if(x < 0 || x >= n || y < 0 || y >= m) continue;

                if(dist[x][y] > h + grid[x][y]){
                    dist[x][y] = h + grid[x][y];
                    pq.push({dist[x][y], x, y});
                }
            }
        }

        return health > dist[n - 1][m - 1];
    }
};