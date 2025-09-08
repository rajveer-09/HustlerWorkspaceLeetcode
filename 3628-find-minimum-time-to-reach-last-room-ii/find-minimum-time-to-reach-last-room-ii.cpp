class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();

        vector<vector<long long>> dist(n, vector<long long>(m, LLONG_MAX));

        priority_queue<array<long long,4>, vector<array<long long,4>>, greater<>> pq;

        dist[0][0] = 0;
        pq.push({0, 0, 0, 0}); // time, i, j, parity

        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        while (!pq.empty()) {
            auto [t, x, y, p] = pq.top(); 
            pq.pop();

            if (x == n - 1 && y == m - 1) {
                return t;
            }

            if (t > dist[x][y]) {
                continue;
            }

            for (auto &d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                    continue;
                }

                int cost = (p == 0 ? 1 : 2);
                long long nt = max((long long)moveTime[nx][ny], t) + cost;

                if (nt < dist[nx][ny]) {
                    dist[nx][ny] = nt;
                    pq.push({nt, nx, ny, 1 - p});
                }
            }
        }
        
        return -1;
    }
};
