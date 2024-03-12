class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        
        vector<vector<int>> merged;
        vector<int> currentInterval = intervals[0];
        
        for (int i = 1; i < intervals.size(); ++i) {
            const vector<int>& nextInterval = intervals[i];
            
            if (nextInterval[0] <= currentInterval[1]) {
                currentInterval[1] = max(currentInterval[1], nextInterval[1]);
            } else {
                merged.push_back(currentInterval);
                currentInterval = nextInterval;
            }
        }
        
        merged.push_back(currentInterval);
        
        return merged;
    }
};