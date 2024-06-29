class Solution {
public:
    static vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> deg(n, 0);
        vector<vector<int>> adj(n);

        for (auto& e: edges) {//Build adjacent list
            int v=e[0], w=e[1];
            adj[v].push_back(w);
            deg[w]++;// indegree
        }

        queue<int> q;
        for(int i=0; i<n; i++)
            if (deg[i]==0) q.push(i);// vertices without ancestors

        vector<vector<int>> ancestor(n);
        
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            
            for (int w : adj[v]) {
                auto& aw=ancestor[w];
                // Add v and all ancestors of v to the ancestors[w]
                aw.push_back(v);
                aw.insert(aw.end(), ancestor[v].begin(), ancestor[v].end());
                
                // Sort and remove duplicates
                sort(aw.begin(), aw.end());
                int sz=1, az=aw.size();
                
                for (int i=1; i<az; i++) {
                    if (aw[i]!=aw[i-1]) 
                        aw[sz++]=aw[i];
                }
                aw.resize(sz);

                if (--deg[w] == 0) q.push(w); //push vertex with 0 deg
            }
        }
        
        return ancestor;
    }
};




auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();