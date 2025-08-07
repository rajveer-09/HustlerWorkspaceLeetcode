class Solution {
public:
    void dfs(vector<vector<int>>& adj, int node, int target, vector<int>& path, vector<vector<int>>& ans){
        path.push_back(node);

        if(node == target){
            ans.push_back(path);
            path.pop_back();
            return;
        }

        for(int ngh : adj[node]){
            dfs(adj, ngh, target, path, ans);
        }

        path.pop_back();

        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
 
        vector<int> path;
        vector<vector<int>> ans;

        dfs(graph, 0, n - 1, path, ans);

        return ans;
    }
};