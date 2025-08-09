class Solution {
public:
    vector<int> bfs(int start, vector<int>& edges) {
        int n = edges.size();
        vector<int> dist(n, INT_MAX);
        queue<int> q;

        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            int nei = edges[node];
            if (nei != -1 && dist[nei] == INT_MAX) {
                dist[nei] = dist[node] + 1;
                q.push(nei);
            }
        }
        return dist;
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> dist1 = bfs(node1, edges);
        vector<int> dist2 = bfs(node2, edges);

        int ans = -1, minMaxDist = INT_MAX;
        for (int i = 0; i < edges.size(); i++) {
            if (dist1[i] != INT_MAX && dist2[i] != INT_MAX) {

                int maxDist = max(dist1[i], dist2[i]);

                if (maxDist < minMaxDist) {
                    minMaxDist = maxDist;
                    ans = i;
                }
            }
        }
        
        return ans;
    }
};