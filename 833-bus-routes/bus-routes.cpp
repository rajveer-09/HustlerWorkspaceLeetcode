class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& R, int src, int tgt) {
        if (src == tgt) return 0;
        int n = R.size();
        vector<vector<int>> adj(1e6 + 1);
        for (int i = 0; i < n; ++i){
            for (int stop : R[i]){
                adj[stop].push_back(i);
            }
        }
            

        vector<bool> busVis(n, false);
        unordered_set<int> stopVis;
        queue<pair<int, int>> q;
        
        q.push({src, 0});
        stopVis.insert(src);

        while (!q.empty()) {
            int stop = q.front().first, cnt = q.front().second; q.pop();

            for (int b : adj[stop]) {
                if (busVis[b]) continue;
                busVis[b] = true;

                for (int next : R[b]) {
                    if (next == tgt) return cnt + 1;

                    if (!stopVis.count(next)) {
                        q.push({next, cnt + 1});
                        stopVis.insert(next);
                    }
                }
            }
        }

        return -1;
    }
};
