class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);

        // Build tree
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        queue<int> q;

        // Step 1: Remove all leaves with no coins
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1 && coins[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                degree[v]--;
                if (degree[v] == 1 && coins[v] == 0)
                    q.push(v);
            }
            degree[u] = 0;
        }

        // Step 2: Remove leaves (twice) to simulate "must go and return"
        for (int round = 0; round < 2; ++round) {
            for (int i = 0; i < n; ++i) {
                if (degree[i] == 1){
                    q.push(i);
                }
            }
            while (!q.empty()) {
                int u = q.front(); q.pop();
                
                for (int v : adj[u]) {
                    if (degree[v] > 0) {
                        degree[v]--;
                    }
                }
                
                degree[u] = 0;
            }
        }

        // Count remaining edges
        int remaining_edges = 0;
        
        for (int i = 0; i < n; ++i) {
            if (degree[i] > 0) {
                remaining_edges += degree[i];
            }
        }

        return remaining_edges;
    }
};