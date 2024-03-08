class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        vector<int> prefixSum(nums.size() + 1, 0);

        // Calculate prefix sum
        for (int i = 1; i <= nums.size(); ++i) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }

        // Check subarrays sum
        for (int start = 0; start < nums.size(); ++start) {
            for (int end = start + 1; end <= nums.size(); ++end) {
                if (prefixSum[end] - prefixSum[start] == k) {
                    count++;
                }
            }
        }

        return count;
    }
};
