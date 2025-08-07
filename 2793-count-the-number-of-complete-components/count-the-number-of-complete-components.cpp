class Solution {
private:
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis, int& nodes, int& edgeCount) {
        vis[u] = true;
        nodes++;
        edgeCount += adj[u].size();
        
        for (int v : adj[u]) {
            if (!vis[v]) {
                dfs(v, adj, vis, nodes, edgeCount);
            }
        }
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> vis(n, false);
        int completeComponents = 0;
        
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                int nodes = 0;
                int edgeCount = 0;
                dfs(i, adj, vis, nodes, edgeCount);

                if (edgeCount == (long long)nodes * (nodes - 1)) {
                    completeComponents++;
                }
            }
        }
        
        return completeComponents;
    }
};