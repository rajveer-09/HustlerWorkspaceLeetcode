class Solution {
public:
    const int MOD = 1e9 + 7;
    typedef pair<long long, int> P; // {time, node}

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<P>> adj(n);
        for (auto &r : roads) {
            adj[r[0]].push_back({r[2], r[1]}); // {time, node}
            adj[r[1]].push_back({r[2], r[0]});
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<long long> dist(n, 1e15);
        vector<int> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [time, city] = pq.top();
            pq.pop();

            // if (time > dist[city]) continue; // skip outdated

            for (auto [tt, ng] : adj[city]) {
                long long newTime = time + tt;

                if (newTime == dist[ng]) {
                    ways[ng] = (ways[ng] + ways[city]) % MOD;
                } 
                else if (newTime < dist[ng]) {
                    dist[ng] = newTime;
                    ways[ng] = ways[city];
                    pq.push({newTime, ng});
                }
            }
        }

        return ways[n - 1];
    }
};
