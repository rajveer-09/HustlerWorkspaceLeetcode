class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; ++i) {
            long long x1 = bombs[i][0];
            long long y1 = bombs[i][1];
            long long r1 = bombs[i][2];

            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                long long x2 = bombs[j][0];
                long long y2 = bombs[j][1];

                long long dist_sq = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);

                if (dist_sq <= r1 * r1) {
                    adj[i].push_back(j);
                }
            }
        }

        int max_detonations = 0;

        for (int i = 0; i < n; ++i) {
            int current_detonations = 0;
            vector<bool> visited(n, false);
            queue<int> q;

            q.push(i);
            visited[i] = true;
            current_detonations++;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                        current_detonations++;
                    }
                }
            }
            
            max_detonations = max(max_detonations, current_detonations);
        }

        return max_detonations;
    }
};