class Solution {
public:
    void dfs(int node, int& cnt, vector<vector<int>>& adj, unordered_set<int>& st, vector<int>& vis){
        if(st.count(node)) return;
        cnt++;
        vis[node] = 1;

        for(auto ngh : adj[node]){
            if(!vis[ngh]){
                dfs(ngh, cnt, adj, st, vis);
            }
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_set<int> st(restricted.begin(), restricted.end());

        vector<vector<int>> adj(n);
        vector<int>vis(n, 0);

        for(auto ed : edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }

        int cnt = 0;

        dfs(0, cnt, adj, st, vis);

        return  cnt;
    }
};