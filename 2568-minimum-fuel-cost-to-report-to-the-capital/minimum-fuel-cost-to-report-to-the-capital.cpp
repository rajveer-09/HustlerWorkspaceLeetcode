class Solution {
private:
    vector<vector<int>> adj;
    long long res = 0;

public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        adj.resize(n);

        for (auto& road : roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }

        dfs(0, -1, seats);
        return res;
    }

private:
    int dfs(int node, int parent, int seats) {
        int passengers = 0;
        for (int child : adj[node]) {
            if (child != parent) {
                int p = dfs(child, node, seats);
                passengers += p;
                res += ceil((double) p / seats);
            }
        }
        return passengers + 1;
    }
};