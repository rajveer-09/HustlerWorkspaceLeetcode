class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& vis) {
        vis[node] = true;

        for (int ngh : graph[node]) {
            if (!vis[ngh]) {
                dfs(ngh, graph, vis);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> graph(n);
        
        // Build graph: connect stones that share a row or column
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        int components = 0;
        vector<bool> vis(n, false);

        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                dfs(i, graph, vis);
                components++;
            }
        }

        return n - components;
    }
};