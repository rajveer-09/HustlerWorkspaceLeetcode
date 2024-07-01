class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(begin(points), end(points), [](const auto& a, const auto& b) {
            return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
        });

        int result = 0;
        for (int i = 0; i < size(points); ++i) {
            for (int j = i + 1, y = numeric_limits<int>::min(); j < size(points); ++j) {
                if (points[i][1] < points[j][1]) {
                    continue;
                }
                if (points[j][1] > y) {
                    y = points[j][1];
                    ++result;
                }
            }
        }
        return result;
    }
};