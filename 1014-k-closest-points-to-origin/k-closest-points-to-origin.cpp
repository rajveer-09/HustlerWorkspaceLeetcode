class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;
        
        for (int i = 0; i < points.size(); ++i) {
            int x = points[i][0], y = points[i][1];
            // No need for sqrt since we're comparing
            int distance = x * x + y * y;
            
            pq.push({distance, i});
            
            // If heap size exceeds k, remove the farthest point
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<vector<int>> result;
        
        while (!pq.empty()) {
            int index = pq.top().second;
            result.push_back(points[index]);
            pq.pop();
        }
        
        return result;
    }
};