class Solution {
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }

    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> x_coords;
        // x_coords.reserve(points.size());
        for (const auto& p : points)
            x_coords.push_back(p[0]);

        sort(x_coords.begin(), x_coords.end());
        int max_val = numeric_limits<int>::min();
        for (int i = 1; i < x_coords.size(); i++)
            max_val = max(max_val, x_coords[i] - x_coords[i-1]);

        return max_val;
    }
};