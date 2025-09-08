class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        vector<vector<bool>> isConnected(n, vector<bool>(n, false));
        
        for (const auto& road : roads) {
            int u = road[0];
            int v = road[1];
            degree[u]++;
            degree[v]++;
            isConnected[u][v] = true;
            isConnected[v][u] = true;
        }

        int maxRank = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int currentRank = degree[i] + degree[j];

                if (isConnected[i][j]) {
                    currentRank--;
                }
                
                maxRank = max(maxRank, currentRank);
            }
        }
        
        return maxRank;
    }
};