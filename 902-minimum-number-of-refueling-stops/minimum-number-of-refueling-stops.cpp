class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        int i = 0, ans = 0;
        long curr = startFuel;
        
        priority_queue<int> pq;

        while (curr < target) {
            while (i < n && stations[i][0] <= curr) {
                pq.push(stations[i][1]);
                i++;
            }

            if (pq.empty()) return -1;

            curr += pq.top();

            pq.pop();
            ans++;
        }

        return ans;
    }
};
