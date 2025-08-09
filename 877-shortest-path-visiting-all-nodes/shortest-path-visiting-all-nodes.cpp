class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 1) return 0;

        queue<pair<int, int>> q; // {node, visited_mask}
        
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));

        for (int i = 0; i < n; i++) {
            int mask = (1 << i);
            
            q.push({i, mask});
            
            visited[i][mask] = true;
        }
        
        int steps = 0;
        int allVisited = (1 << n) - 1;

        while (!q.empty()) {
            int sz = q.size();
            
            while (sz--) {
                auto [node, mask] = q.front(); q.pop();

                if (mask == allVisited) return steps;

                for (int nei : graph[node]) {
                    int newMask = mask | (1 << nei);
                    
                    if (!visited[nei][newMask]) {
                        visited[nei][newMask] = true;
                        q.push({nei, newMask});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};