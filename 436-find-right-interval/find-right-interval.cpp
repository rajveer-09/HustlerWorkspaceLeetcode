class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> startPoints;
        vector<int> ans(intervals.size());

        for (int i = 0; i < intervals.size(); i++) {
            startPoints.push_back({intervals[i][0], i});
        }
        sort(startPoints.begin(), startPoints.end());

        for (int i = 0; i < intervals.size(); i++) {
            auto it = lower_bound(startPoints.begin(), startPoints.end(), make_pair(intervals[i][1], -1));
            if (it != startPoints.end()) {
                ans[i] = it->second;
            } else {
                ans[i] = -1;
            }
        }
        return ans;
    }
};