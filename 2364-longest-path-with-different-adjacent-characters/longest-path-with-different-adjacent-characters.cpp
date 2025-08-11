class Solution {
public:
    int maxi = 0;
    int dfs(int node, vector<vector<int>>& adj, vector<int>& vis, string& s) {
        vis[node] = 1;
        
        int longest1 = 0;  // longest child path length
        int longest2 = 0;  // second longest child path length
        
        for(int ngh : adj[node]){
            if(!vis[ngh]){
                int child = dfs(ngh, adj, vis, s);
                
                if(s[ngh] != s[node]){
                    if(child > longest1){
                        longest2 = longest1;
                        longest1 = child;
                    } 
                    else if(child > longest2){
                        longest2 = child;
                    }
                }
            }
        }
        
        maxi = max(maxi, 1 + longest1 + longest2);
        
        return longest1 + 1;
    }

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        
        vector<vector<int>>adj(n);
        for(int i = 0 ;i < n; i++){
            if(parent[i] == -1) continue;

            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
        
        vector<int> vis(n, 0);
        
        int ans = dfs(0, adj, vis, s);
        
        
        return maxi;
    }
};