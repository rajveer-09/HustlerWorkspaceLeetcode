class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<bool>& visited){
        visited[node] = true;

        for(int it : adj[node]){
            if(!visited[it]){
                dfs(it, adj, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int cnt = 0;

        vector<bool> visited(n);

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                cnt++;
                dfs(i, adj, visited);
            }
        }

        return cnt;
    }
};

/* To traverse all the connected things use -> BFS / DFS */