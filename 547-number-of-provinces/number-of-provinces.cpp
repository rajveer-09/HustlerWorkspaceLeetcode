class Solution {
  public:
    void dfs(vector<int> adj[], int st, vector<bool>& visited){
        visited[st] = true;

        for(int it : adj[st]){
            if(!visited[it]){
                dfs(adj, it, visited);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>> Adj) {
        int V = Adj.size();
        vector<int> adj[V];
        
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(Adj[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> visited(V, false);

        int cnt = 0;
    
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                cnt++;
                dfs(adj, i, visited);
            }
        }
        return cnt;
    }
};