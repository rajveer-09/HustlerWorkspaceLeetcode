class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return {};
        
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());

        int mini = intervals[0][0];
        int maxi = intervals[0][1];
        
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] <= maxi) {
                if (intervals[i][1] > maxi) {
                    maxi = intervals[i][1];
                }
            } else {
                ans.push_back({mini, maxi});
                mini = intervals[i][0];
                maxi = intervals[i][1];
            }
        }
        
        ans.push_back({mini, maxi});
        
        return ans;
    }
};