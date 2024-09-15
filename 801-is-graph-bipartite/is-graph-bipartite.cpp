class Solution {
public:
    bool DFS(int curr, int currColor, vector<vector<int>>& graph, vector<int>& color){
        color[curr] = currColor;
        
        for(auto x: graph[curr]){
            if(color[x] == color[curr]) return false;
            
            if(color[x] == -1){
                bool ans = DFS(x, 1-currColor, graph, color);
                if(!ans) return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<int>color(V, -1);
	    for(int i = 0; i < V; i++){
	        if(color[i] == -1){
	            bool ans = DFS(i, 0, graph, color);
	            if(!ans) return false;
	        }
	    }
	    return true;
    }
};