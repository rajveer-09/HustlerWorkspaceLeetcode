class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        if (nums1.empty() || nums2.empty() || k == 0) return result;

        // Min-heap: {sum, {i, j}} where i, j are indices in nums1 and nums2
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> minHeap;

        // Push first k elements from nums1 paired with nums2[0]
        for (int i = 0; i < nums1.size() && i < k; i++) {
            minHeap.push({nums1[i] + nums2[0], {i, 0}});
        }

        while (!minHeap.empty() && result.size() < k) {
            auto [sum, indices] = minHeap.top(); minHeap.pop();
            int i = indices.first;
            int j = indices.second;

            result.push_back({nums1[i], nums2[j]});

            // Move to next index in nums2 for the same nums1[i]
            if (j + 1 < nums2.size()) {
                minHeap.push({nums1[i] + nums2[j + 1], {i, j + 1}});
            }
        }

        return result;
    }
};
