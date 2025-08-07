class Solution {
public:
    int dfs1(int u, int p, const vector<vector<pair<int, int>>>& adj) {
        int cost = 0;
        for (auto& [v, rev] : adj[u]) {
            if (v == p) continue;
            cost += rev + dfs1(v, u, adj);
        }

        return cost;
    }
    void dfs2(int u, int p, const vector<vector<pair<int, int>>>& adj, vector<int>& ans) {
        for (auto& [v, rev] : adj[u]) {
            if (v == p) continue;

            ans[v] = ans[u] + (rev == 0 ? 1 : -1);

            dfs2(v, u, adj, ans);
        }
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], 0}); 
            adj[e[1]].push_back({e[0], 1}); 
        }
        vector<int> ans(n);
        
        ans[0] = dfs1(0, -1, adj);

        dfs2(0, -1, adj, ans);
        
        return ans;
    }
};