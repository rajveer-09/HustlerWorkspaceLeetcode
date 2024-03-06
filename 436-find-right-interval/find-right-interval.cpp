class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> startPoints;
        vector<int> ans;

        for (int i = 0; i < intervals.size(); i++) {
            startPoints[intervals[i][0]] = i;
        }

        for (auto& interval : intervals) {
            auto it = startPoints.lower_bound(interval[1]);
            if (it != startPoints.end()) {
                ans.push_back(it->second);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};